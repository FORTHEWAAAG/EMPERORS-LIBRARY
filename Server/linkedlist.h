#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../SocketWrapper/CryptServerWrap.h"


using std :: cout;
using std :: endl;


class Node : public TLS_session{
    public:
        explicit Node(int id, uint16_t port) : TLS_session(id, port){};
        void add(int id, uint16_t port);
        ~Node();

        Node * prev = nullptr;
        Node * next = nullptr;
};


void Node :: add(int id, uint16_t port){
    cout << "Adding node" << endl;
    if(prev == nullptr) next = new Node(id, port);
    else{
        Node * temp = this->next;
        while(temp != nullptr){
            temp = temp->next;
            cout << "Updatig" << endl;
            }
         temp->next = new Node(id, port);
//    delete(&temp);
        }
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
