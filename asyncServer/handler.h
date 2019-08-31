#ifndef HANDLER_H
#define HANDLER_H

#include "linkedlist.h"


using std :: cerr;         
using std :: cout;         
using std :: endl;         


class Handler{
    public:
        Handler(uint16_t port, size_t max_connectors);
        ~Handler();
        void update();
        void add_connection();
        bool is_alive(int id);

        size_t connectors = 0, max_num = 0;
        uint16_t port_handler = 0;
        Node * linkedlist = nullptr;
};


Handler :: Handler(uint16_t port, size_t max_connectors){
    cout << "Initi handler" << endl;
    this->linkedlist = new Node(port++);
    cout << "linkedlist created" << endl;
    this->port_handler = port;
    this->max_num = max_connectors;
}


bool Handler :: is_alive(int id){
    int error_code = -1;
    getsockopt(id, SOL_SOCKET, SO_ERROR, &error_code, (socklen_t*)sizeof(error_code));
    if(error_code == 0) cout << "Alive" << endl;
    else cout << "Dead" << endl;
    return error_code == 0;
}


void Handler :: update(){
    size_t cons = 0;
    Node * connection = this->linkedlist;
    while(connection != nullptr){
        if(is_alive(connection->sock_id)) ++cons;
        connection = connection->next;
        }
    this->connectors = cons;
}


void Handler :: add_connection(){
    cout << "Adding new connector to linkedlist" << endl;
    if(this->connectors >= this->max_num) cerr << "Connectors number overflow" << endl;
    else{
        this->linkedlist->add(this->port_handler++);
        ++this->connectors;
        cout << "Current num of connectors" << endl;
    }
}


Handler :: ~Handler(){
    cout << "Destruction of handler" << endl;
    /*
    if(this->linkedlist != nullptr){
        Node * prev = this->linkedlist;
        while(prev != nullptr){
            Node * cur = prev;
            prev = cur->prev;
            delete(cur);
        }
#endif    }*/
}

#endif //HANDLER_H