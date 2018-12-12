#include <sys/statvfs.h>
#include <math.h>
#include <fstream>

struct statvfs inf;

double * physical_mem_usage(){
    statvfs(".", &inf);
    auto _hdd = new double [2];
    _hdd[0]=(inf.f_blocks * inf.f_frsize);
    _hdd[1]=(_hdd[0] - inf.f_bavail * inf.f_frsize);

    _hdd[0]/=1000000000.0;
    _hdd[1]/=1000000000.0;

    _hdd[0] =floor(_hdd[0]*100)/100;
    _hdd[1] = floor(_hdd[1]*100)/100;

    return _hdd;
}

double * process_mem_usage(){
    auto _mem = new double [2];
    unsigned long vsize;
    long rss;
    {
        std::string ignore;
        std::ifstream ifs("/proc/self/stat", std::ios_base::in);
        ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
            >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
            >> ignore >> ignore >> vsize >> rss;
    }

    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages

    _mem[0] = vsize / 1024.0 / 1024.0;
    _mem[0] = floor(_mem[0]*100)/100;

    _mem[1] = (rss * page_size_kb)/1024.0;
    _mem[1]=floor(_mem[1]*100)/100;

    return _mem;
}

