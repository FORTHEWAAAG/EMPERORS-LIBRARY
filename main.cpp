#ifdef __linux__
#include "server.h"
#include "iostream"

using std::cout, std::endl;

int main() {
    string data;
    auto cnct = new Server;
    cnct->set_up();
    while(cnct->access()){
        cnct->conn();
        //data = cpu_num() + get_cpu() + process_mem_usage() + physical_mem_usage();
        cout << data << endl;
        cnct->Snd();
        cnct->off();
        sleep(5);
    }
    return 0;
}

#elif _WIN32


#else

#endif