#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../SocketWrapper/ServerWrap.h"


using std :: cout;
using std :: endl;


class Node : public Connector{
    public:
        explicit Node(int id, uint16_t port) : Connector(id, port){};
        void add(int id, uint16_t port);
        ~Node();

        Node * prev = nullptr;
        Node * next = nullptr;
};


void Node :: add(int id, uint16_t port){
    cout << "Adding node" << endl;
    Node * temp = this->next;
    while(temp != nullptr){
        temp = temp->next;
        cout << "Updatig" << endl;
    }
    temp = new Node(id, port);
//    delete(&temp);
}


Node :: ~Node(){
    if(this->next != nullptr && this->prev == nullptr) this->next->prev = nullptr;
    else if(this->next == nullptr && this->prev != nullptr) this->prev->next = nullptr;
    else{
        this->prev = this->next;
        this->next = this->prev;
    }
}

#endif //LINKED_LIST_H
