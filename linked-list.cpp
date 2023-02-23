// implementation of
// the Linked list in C++

#include <bits/stdc++.h>

using namespace std;
typedef int Type;

// class to define a cell, that contain value and the address in RAM (that can link) to another cell
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

class linkedList{
    Node* head;

    public:
        linkedList(){
            head = nullptr;
        }

        // check if a list is empty ( == nullptr -> == 0x0)
        bool isEmpty(){ return ( head == nullptr); }

        //return size of Type list
        int size () {
            int count = 1;
            Node* cur = head->next;
            while (cur != nullptr){
                count++;
                cur = cur->next;
            }
            return count;
        }

        // return value at index 
        Type value_at(int index){
            int i = 0;
            Node* cur = head;
            if (index >= size()){
                return -1;
            }
            while (cur != nullptr && i != index){
                if (i > index){
                    return -1;
                }
                i++;
                cur = cur->next;
            }
            return cur->value;
        }
        // insertion at the head
        void push_front (Type value){
            Node* aux  = new Node;
            aux->value = value;
            aux->next = head;
            head = aux;
        }

        // deletion at the head
        void pop_front (){
            if (head == nullptr)
                return;
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // insertion at the end
        void push_back (Type value){
            if (isEmpty()){
                push_front (value);
                return;
            }
            Node* cur  = head;
            Node* prev = cur;
            while (cur != nullptr)
            {
                prev = cur;
                cur = cur ->next;
            }
            Node* aux = new Node;
            aux->value = value;
            aux->next = cur;
            prev->next = aux;
        }
        
        // removes end item and returns its value
        Type pop_back (){
            if (isEmpty()){
                cout << "List is empty" << endl;
                return -1;
            }
            Node* cur = head;
            Node* prev = cur;
            while (cur->next != nullptr){
                prev = cur;
                cur = cur->next;
            }
            prev->next = nullptr;
            Type x = cur->value;
            delete cur;
            return x;
        }

        // print a list of Type
        void print_list (){
            Node* cur = head;
            while (cur != nullptr){
                cout << cur->value << " -> ";
                cur = cur->next;
            }
            cout << "0x0";
            return;
        }

        // return first element of a Type list
        Type front (){
            Node* cur = head;
            return cur ->value;
        }

        // return last of a Type list
        Type back (){
            Node* cur = head->next;
            Node* prev = nullptr;
            while (cur != nullptr){
                prev = cur;
                cur = cur ->next; 
            }
            return prev->value;
        }
        // insertion a value at index in Type list
        void insert(int index, Type value){
            if (isEmpty()){
                cout << endl << "index out of range (List is empty)" << endl;
                return;
            }
            if (index == 0){
                push_front(value);
                return;
            }
            //sanity check : index
            if (index < 0 || index > size()){
                cout << endl << "index out of range";
                return;
            }
            Node* cur = head;
            Node* prev = cur;
            for (int i = 0; i < index; ++i){
                prev = cur;
                cur = cur->next;
            }       
            Node * aux = new Node;
            aux->value = value;
            aux->next = cur;
            prev->next = aux;
        }

        // removes node at given index
        void erase (int index){
            if (isEmpty()){
                cout << endl << "index out of range (List is empty)" << endl;
                return;
            }
            if (index == 0){
                pop_front();
                return;
            }
             //sanity check : index
            if (index < 0 || index > size()-1){
                cout << endl << "index out of range" << endl;
                return;
            }
            Node* cur = head;
            Node* prev = cur;
            for (int i = 0; i < index; ++i){
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
        }

        // removes the first item in the list with this value
        void remove_value(Type value){
            if (isEmpty()){
                cout << endl << "index out of range (List is empty)" << endl;
                return;
            }
            Node* cur = head;
            Node* prev = cur;
            if (head->value == value){
                head = head->next;
                delete cur;
                return;
            }
            while (cur->next != nullptr){
                if (cur->value == value){
                    prev->next = cur->next;
                    delete cur;
                    // update pointers
                    cur = prev->next; 
                }else{
                    prev = cur;
                    cur = cur->next;
                }
            }
            // check last node in the list
            if (cur->value == value){
                prev->next = nullptr;
                delete cur;
                
            }else{
                cout << endl << "value not found" << endl;
            }
            return;  
        }
        // reverse the list
        void reverse (){
            if (isEmpty()){
                return;
            }
            Node* cur = head;
            Node* prev = nullptr;
            Node* next = nullptr;
            while (cur != nullptr){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            head = prev;
            return;
        }
};

// Test
int main (){
    linkedList lst;
    lst.push_front (10);
    lst.push_front (20);
    lst.push_front (30);
    cout << "Size after two push_front(): " << lst.size () << endl;
    cout << "List elements: ";
    lst.print_list ();
    cout << endl << "Value at index 1: "<< lst.value_at (1);
    cout << endl << "Front value: " << lst.front ();
    cout << endl << "Back value: " << lst.back ();
    lst.pop_front ();
    cout << endl << "Size after pop_front(): " << lst.size () << endl;
    cout << "List elements: ";
    lst.print_list ();
    lst.insert (1, 15);
    cout << endl << "List Elements after insertion 15 at index 1: ";
    lst.print_list();
    cout << endl << "List after push back: ";
    lst.push_back (40);
    lst.print_list ();
    cout << endl << "List after pop back: ";
    lst.pop_back ();
    lst.print_list ();
    cout << endl << "List after delete values at index 1: ";
    lst.erase (2);
    lst.print_list ();
    cout << endl << "List after remove 15: ";
    lst.remove_value (15);
    lst.print_list ();
    lst.push_front (25);
    lst.push_front (30);
    cout << endl << "List elements after 2 push front: ";
    lst.print_list ();
    cout << endl << "Reverse list elements: ";
    lst.reverse ();
    lst.print_list ();
    return 0;
}
