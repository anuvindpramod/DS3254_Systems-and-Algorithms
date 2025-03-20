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

        void insertend(int val){
            Node* newNode=new Node(val);
            if (!head){
                head=newNode;
                return;
            }

            Node* curr=head;
            while (curr->next){
                curr=curr->next;
            }
            curr->next=newNode;

        }
        void transverse(){
            Node* curr=head;
            while(curr!=nullptr){
                cout<<curr->data<<endl;
                curr=curr->next;
            }
            cout<<"Null"<<endl;
        }
};

int main(){
    Linkedlist list;
    list.insertend(49);
    list.insertend(56);
    list.insertend(78);
    list.transverse();
    return 0;

}
