#include "../../SocketWrapper/ClientWrap.h"
#include "../../util/proc.h"
#include "../../util/memory.h"


static const uint16_t to_port = 44301;
static const uint16_t from_port = 44300;
static const char * from_addr = "127.0.0.1";
static const char * to_addr = "127.0.0.1";

int main() {
    string data;
    ClientSock client(from_addr, from_port, to_addr, to_port);
    while(gethostbyname(to_addr)){
        data = "| " + cpu_num() + " | " + get_cpu() +" | "+ process_mem_usage() +" | "+ physical_mem_usage() + " |";
        cout << data << endl;
        client.send_wr(data);
    }
    return 0;
}
