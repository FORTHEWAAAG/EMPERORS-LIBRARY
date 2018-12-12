#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "proc.h"
#include "memory.h"

using std::cerr;

class Server
{
private:
    uint16_t port=44300;
    uint32_t from_addr;
    uint32_t to_addr;
    struct sockaddr_in serverAddress, clientAddress;

public:
    char Format();
    Server();
    ~Server();
    void set_up();
    bool access();
    void conn();
    bool Snd();
    void off();
    int sockfd, newsockfd;
    socklen_t len;
};

Server::Server(){
    this->sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(!this->sockfd) cerr << "Error of socket opening-1";

    this->serverAddress.sin_family=AF_INET;
    this->serverAddress.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
    this->serverAddress.sin_port=htons(port);

    this->clientAddress.sin_family=AF_INET;
    this->clientAddress.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
    this->clientAddress.sin_port=htons(port);
    this->len = sizeof((struct sockaddr*)&clientAddress);
}

Server::~Server(){
    close(sockfd);
}

void Server::set_up(){
    if((bind(sockfd,(struct sockaddr *)&serverAddress, sizeof(serverAddress)))<0) {
        cerr << "Error of binding";
        socklen_t enabled = 1;
        setsockopt(sockfd, IPPROTO_TCP, SO_REUSEADDR, &enabled, sizeof(enabled));
    }
}

void Server::conn() {
    listen(sockfd, 1);
    newsockfd = accept(sockfd, (struct sockaddr *) &clientAddress, (socklen_t *) &len);
    if (newsockfd < 0) {
        cerr << "Acception error";
    };
}

bool Server::access(){
    return gethostbyname("127.0.0.1");
}

char Server::Format(){
    double _num = cpu_num();
    double _cpu = get_cpu();
    double *_ram = process_mem_usage();
    double *_load = _ram + 1;
    double *_hdd = physical_mem_usage();
    double *_eng = _hdd + 1;
    using std::cout;
    using std::endl;
    cout <<*_ram<<endl<<*_load<<endl<<*_hdd<<endl<<*_eng<<endl;
}

bool Server::Snd(){
    Server::Format();
    /*char message[data.length()+1];
    strcpy(message, data.c_str());
    return send(newsockfd, &message, sizeof(message), 0);*/
    return true;
}

void Server::off(){
    close(newsockfd);
}
