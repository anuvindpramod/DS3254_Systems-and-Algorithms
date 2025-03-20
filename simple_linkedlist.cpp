#include <iostream>
using namespace std;

//Define the struture of the node

struct Node {
    int data;
    Node* next;

    //initailze a new node

    Node(int val ){
        data= val;
        next=nullptr;
    }
};

//linked list class

class LinkedList{
private: 
    Node* head; //points to the first node

public: 
    LinkedList(){
        head=nullptr;
    }

    //insert at front
    void insertionFront(int val){
        Node* newNode=new Node(val); //create new node
        newNode->next=head; //linked new to previous head
        head=newNode;

    }
    void transverse(){
        Node* curr=head;
        while (curr!=nullptr){
            cout<<curr->data<<"-->";
            curr=curr->next;
        }
        cout<<"Null"<<endl;
    }

};

int main(){
    LinkedList list;
    list.insertionFront(10);
    list.insertionFront(20);
    list.insertionFront(40);

    list.transverse();
    return 0;
}