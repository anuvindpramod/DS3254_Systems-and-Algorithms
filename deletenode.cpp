#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};

class Linkedlist{
private:
    Node* head;
public:
    Linkedlist(){
        head=nullptr;
    }

    void insertfront(int val){
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;

    }
    void deletenode(int val){
        if(!head){
            return;
        }
        if (head->data==val){
            Node* temp=head;
            head=head->next;
            delete temp;
            return;

        }
        Node* curr=head;
        while(curr->next && curr->next->data !=val){
            curr=curr->next;

        }
        if(curr->next && curr->next->data==val){
            Node* temp=curr->next;
            curr->next=temp->next;
            delete temp;
        }
    }
    
    bool search(int val){
        Node* curr=head;
        while (curr){
            if (curr->data==val){
                return true;
            }
            curr=curr->next;
        }
        return false;
    }

    void transverse(){
        Node* curr=head;
        while(curr!=nullptr){
            cout<<curr->data<<"--->";
            curr=curr->next;
        }
        cout<<"NULL"<<endl;
    }

};
int main(){
    Linkedlist list;
    list.insertfront(24);
    list.insertfront(56);
    list.insertfront(24);
    list.insertfront(45);
    list.insertfront(30);
    list.insertfront(10);
    list.insertfront(10);
    list.deletenode(56);
    list.transverse();

    cout << "Found 30? " << (list.search(30) ? "Yes" : "No") << endl;
    cout << "Found 50? " << (list.search(50) ? "Yes" : "No") << endl;

    return 0;
}
