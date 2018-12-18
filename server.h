#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
//#include "proc.h"
//#include "memory.h"
#include "dcmprssDat.h"

using std::cerr;

class Server
{
private:
    uint16_t port=44300;
    uint32_t from_addr;
    uint32_t to_addr;
    struct sockaddr_in serverAddress, clientAddress;

public:
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

bool Server::Snd(){
    char * telemetry;
    Gzip zip;
    string data =zip.compress();
    telemetry = new char[zip.data_amount()];
    strcpy(telemetry, data.c_str());
    //zip.decompress();
    /*
    std::stringstream ss;
    ss<<sysconf(_SC_NPROCESSORS_ONLN)<<"/"<<get_cpu()<<"/"<<
    *(process_mem_usage())<<"/"<<*(process_mem_usage()+1)<<"/"<<
    *(physical_mem_usage())<<"/"<<*(physical_mem_usage()+1);
    char telemetry[sizeof(ss)/8];
    ss>>telemetry;
    std::cout<<telemetry<<std::endl;*/
    return send(newsockfd, &telemetry, sizeof(telemetry), 0)==0;


}

void Server::off(){
    close(newsockfd);
}
