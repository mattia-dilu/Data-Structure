// implementation of
// Stack with linked list in C++


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

class Stack{
     Node* head;

    public:
        Stack(){
            head = nullptr;
        }
        bool isEmpty(){ return (head == nullptr);}
        //adds x to collection
        void push(Type x){
            Node* aux = new Node;
            aux->value = x;
            aux->next = head;
            head = aux;
            return;
        }
        // removes and returns most recently-added element
        Type pop(){
            if(isEmpty()){
                cout << "Stack is empty..."<< endl;
                return -1;
            }
            Node* cur = head;
            head = head->next;
            Type tmp = cur->value;
            delete cur;
            return tmp;
        }
        // returns most recently-added element
        Type top(){
            if(isEmpty()){
                cout << "Stack is empty..."<< endl;
                return -1;
            }
            return head->value;
        }
        void print (){
            if (isEmpty()){
                cout << "Stack is empty..."<< endl;
                return;
            }
            Node* cur = head;
            while (cur != nullptr){
                cout << cur->value << " -> ";
                cur = cur->next;
            }
            cout << "0x0" << endl;
            return;

        }
};
//test
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Stack after two push: ";
    s.print();
    cout << "Element at the top: " << s.top() << endl;
    s.push(30);
    cout << "Stack after push 30: ";
    s.print();
    s.pop();
    cout << "Stack after pop: ";
    s.print();
    return 0;
}
