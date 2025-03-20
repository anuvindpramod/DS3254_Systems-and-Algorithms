#include <iostream>
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

class doublylinkedlist{
private:
    Node* head;
public:
    doublylinkedlist(){
        head=nullptr;
    }

    void insertfront(int val){
        Node* newNode=new Node(val);
        if(head){
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;  // Always update head to new node
    }

    void insertend(int val){
        Node* newNode=new Node(val);
        if (!head){
            head=newNode;
            return;
        }
        Node* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=newNode;
        newNode->prev=curr;

    }

    void deletenode(int val){
        if(!head) return;

        // Handle head deletion
        if(head->data == val){
            Node* temp = head;
            head = head->next;
            if(head) head->prev = nullptr;  // Clear new head's prev pointer
            delete temp;
            return;
        }

        Node* curr = head;
        // Safe search for node to delete
        while(curr->next && curr->next->data != val){
            curr = curr->next;
        }

        if(curr->next){
            Node* temp = curr->next;
            curr->next = temp->next;
            if(temp->next){
                temp->next->prev = curr;  // Update next node's prev pointer
            }
            delete temp;
        }
    }

    void transverseforward(){
        if(!head){
            return;
        }
        
        Node* curr=head;
        while(curr){
            cout<<curr->data<< " ⇄ ";
            curr=curr->next;
        }
        cout<<"NULL"<<endl;
    }

    void transversebackward(){
        if(!head) return;
        
        Node* curr = head;
        // Reach the last node first
        while(curr->next){
            curr = curr->next;
        }
        // Now traverse back using prev pointers
        while(curr){
            cout << curr->data << " ⇄ ";
            curr = curr->prev;
        }
        cout << "NULL" << endl;
    }
};


int main() {
    doublylinkedlist dll;
    dll.insertfront(10);
    dll.insertfront(20);
    dll.insertfront(30);
    dll.insertend(40);
    dll.insertend(50);
    
    cout << "Forward Traversal: ";
    dll.transverseforward();

    dll.deletenode(20);

    cout << "After Deletion: ";
    dll.transverseforward();

    cout << "Backward Traversal: ";
    dll.transversebackward();

    return 0;
}
