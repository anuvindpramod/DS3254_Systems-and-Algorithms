#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};  

class circulardoublylinkedlist{
private:
    Node* head;

public:
    circulardoublylinkedlist(){
        head=nullptr;
    }

    void insertend(int val){
        Node* newNode=new Node(val);
        if(!head){
            head=newNode;
            head->next=head;
            head->prev=head;
            return;
        }

        Node* tail=head->prev;
        tail->next=newNode;
           newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    // Traverse the list
    void traverse() {
        if (!head) return;

        Node* curr = head;
        do {
            cout << curr->data << " ⇄ ";
            curr = curr->next;
        } while (curr != head);
        cout << "(back to head)" << endl;
    }
    void deleteNode(int val) {
    if (!head) return;

    Node* curr = head;

    // Case 1: If the head node is to be deleted
    if (head->data == val) {
        if (head->next == head) {  // If only one node
            delete head;
            head = nullptr;
            return;
        }
        Node* tail = head->prev;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete curr;
        return;
    }

    // Case 2: Delete a node that is not the head
    do {
        if (curr->data == val) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            return;
        }
        curr = curr->next;
    } while (curr != head);
}
    
};
    
    

