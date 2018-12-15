#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <thread>
#include <vector>
#include <cmath>
#include <iomanip>

using std::thread;
using std::string;
using std::to_string;
using std::ifstream;
using std::vector;
using std::istringstream;
using std::chrono::milliseconds;

const int NUM_CPU_STATES = 10;

enum CPUStates
{
    S_USER = 0,
    S_NICE,
    S_SYSTEM,
    S_IDLE,
    S_IOWAIT,
    S_IRQ,
    S_SOFTIRQ,
    S_STEAL,
    S_GUEST,
    S_GUEST_NICE
};

typedef struct CPUData
{
    string cpu;
    size_t times[NUM_CPU_STATES];
} CPUData;

void ReadStatsCPU(vector<CPUData> & entries){
    ifstream fileStat("/proc/stat");

    string line;

    string STR_CPU("cpu");
    size_t LEN_STR_CPU = STR_CPU.size();
    string STR_TOT("tot");

    while(getline(fileStat, line))
    {
        // cpu stats line found
        if(!line.compare(0, LEN_STR_CPU, STR_CPU))
        {
            istringstream ss(line);

            // store entry
            entries.emplace_back(CPUData());
            CPUData & entry = entries.back();

            // read cpu label
            ss >> entry.cpu;

            // remove "cpu" from the label when it's a processor number
            if(entry.cpu.size() > LEN_STR_CPU)
                entry.cpu.erase(0, LEN_STR_CPU);
                // replace "cpu" with "tot" when it's total values
            else
                entry.cpu = STR_TOT;
            //cout<<entry.cpu;
            // read times
            for (unsigned long &time : entry.times)
                ss >> time;
        }
    }
}

size_t GetIdleTime(CPUData & e){
    return	e.times[S_IDLE] +
              e.times[S_IOWAIT];
}

size_t GetActiveTime(CPUData & e){
    return	e.times[S_USER] +
              e.times[S_NICE] +
              e.times[S_SYSTEM] +
              e.times[S_IRQ] +
              e.times[S_SOFTIRQ] +
              e.times[S_STEAL] +
              e.times[S_GUEST] +
              e.times[S_GUEST_NICE];
}

double PrintStats(vector<CPUData> & entries1, vector<CPUData> & entries2) {
    static double _cp;
    for (size_t i = 0; i < 1; ++i) {
        CPUData &e1 = entries1[i];
        CPUData &e2 = entries2[i];
        auto ACTIVE_TIME = static_cast<double>(GetActiveTime(e2) - GetActiveTime(e1));
        auto IDLE_TIME = static_cast<double>(GetIdleTime(e2) - GetIdleTime(e1));
        double TOTAL_TIME = ACTIVE_TIME + IDLE_TIME;
        _cp = 100.f * ACTIVE_TIME / TOTAL_TIME;
    }
    return floor(_cp*100)/100;
}

double get_cpu(){
    vector<CPUData> entries1;
    vector<CPUData> entries2;
    ReadStatsCPU(entries1);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    ReadStatsCPU(entries2);
    return (PrintStats(entries1, entries2));
}