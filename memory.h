#include <sys/statvfs.h>
#include <math.h>
#include <fstream>

using std::string, std::to_string;

struct statvfs inf;

string physical_mem_usage(){
    statvfs(".", &inf);

    double _hdd1=(inf.f_blocks * inf.f_frsize);
    double _hdd2=(_hdd1 - inf.f_bavail * inf.f_frsize);

    _hdd1/=1000000000.0;
    _hdd2/=1000000000.0;

    _hdd1 =floor(_hdd1*100)/100;
    _hdd2 = floor(_hdd2*100)/100;

    return to_string(_hdd1)+"/"+to_string(_hdd2);
}

string process_mem_usage(){
    double vm_usage, resident_set;
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

    vm_usage = vsize / 1024.0 / 1024.0;
    vm_usage = floor(vm_usage*100)/100;

    resident_set = (rss * page_size_kb)/1024.0;
    resident_set=floor(resident_set*100)/100;

    return to_string(vm_usage)+"/"+to_string(resident_set)+"/";
}

