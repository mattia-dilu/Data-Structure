// implementation of
// queue in C++ with circular linked list


#include <bits/stdc++.h>

using namespace std;
typedef int Type;


class Node{
    public:
        Type value;
        Node* next;

    // constructor of Node
    Node(){
        value = 0;
        next = nullptr;
    }

    Node (Type value){
        this->value = value;
        this->next = next;
    }
};
class Queue{
    Node* head;
    Node* tail;
    public:
        Queue(){
            head = nullptr;
            tail = nullptr;
        }

        bool isEmpty (){
            return (head == nullptr);
        }
        // adds value to collection
        void enqueue (Type x){
            Node* aux = new Node (x);
            if(isEmpty()){
                head = aux;
            }else{
                tail->next = aux;
            }
            tail = aux;
            tail->next = head;
            return;
        }

        //removes and returns least recently-added value
        Type dequeue (){
            if (isEmpty()){
                return -1;
            }
            Type x;
            if (head == tail){
                x = head->value;
                delete head;
                tail = head = nullptr;
                return x;
            }
            Node* cur = head;
            x = head->value;
            head = head->next;
            tail->next = head;
            delete cur;
            return x;
            
        }
        void print (){
            if (isEmpty()){
                return;
            }
            Node* cur = tail->next;
            while (cur->next != head){
                cout << cur->value << " -> ";
                cur = cur->next;
            }
            cout << cur->value << " -> 0x0" << endl;
            return;
        }
};

// test
int main (){
    Queue q;
    q.enqueue (10);
    q.enqueue (20);
    q.enqueue (30);
    cout << "Print Queue: ";
    q.print ();
    cout << "Print Queue, after dequeue... "<< endl;
    cout << "deletion (" << q.dequeue() << "): ";
    q.print();
    return 0;
}
