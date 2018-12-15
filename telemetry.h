#include <unistd.h>
#include "proc.h"
#include "memory.h"

using std::cout;
using std::endl;
using std::dec;
class data{
protected:
    int _num;
    double _cpu;
    double * _ram, * _hdd;
    char * info;
public:
    data();
    ~data();
    char telemetry_format();
};

char data::telemetry_format(){
    std::stringstream ss;
    ss<<_num<<"/"<<_cpu<<"/"<<*_ram<<"/"<<*(_ram+1)<<"/"<<*_hdd<<"/"<<*(_hdd+1);
    auto telemetry = new char[sizeof(ss)/8];
    ss>>telemetry;
    std::cout<<telemetry<<std::endl;
    return *telemetry;
};

data::data(){
    this->_num = (int)sysconf(_SC_NPROCESSORS_ONLN);
    this->_cpu = get_cpu();
    this->_ram = process_mem_usage();
    this->_hdd = physical_mem_usage();
}

data::~data()=default;