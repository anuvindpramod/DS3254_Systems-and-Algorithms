#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class BST{
private:
    Node* root;

    Node* insertRec(Node* node, int val){
        if(!node){
            return new Node(val);
        }
        if(val<node->data){
            node->left=insertRec(node->left, val);
        }
        else if (val> node->data){
            node->right=insertRec(node->right,val);
        }

        return node;

    }

    void inorderRec(Node* node){
        if (!node){
            return;
        }
        inorderRec(node->left);
        cout<<node->data<<"";
        inorderRec(node->right);
    }

    Node* searchrec(Node* node, int val){
        if (!node){
            return node;
        }
        if (node->data==val){
            return node;
        }
        if (val<node->data){
            return searchrec(node->left,val);   
        }
        return searchrec(node->right,val);

    }
    Node* getMin(Node* node){
        while(node->left){
            node=node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int val){
        if(!node){
            return node;
        }
        if(val<node->data){
            node->left=deleteNode(node->left,val);
        }
        else if(val>node->data){
            node->right=deleteNode(node->right,val);
        }
        else{
            if(!node->left){
                Node* temp=node->right;
                delete node;
                return temp;
            }
            if(!node->right){
                Node* temp=node->left;
                delete node;
                return temp;
            }

            Node* temp=getMin(node->right);
            node->data=temp->data;
            node->right=deleteNode(node->right,temp->data);

        }
        return node;



    }
   
public:
    BST(){
        root=nullptr;
    }

    void insert(int val) {
        root = insertRec(root, val);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    bool search(int val){
        return searchrec(root,val)!=nullptr;
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }
        


};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Searching for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    cout << "Deleting 20\n";
    tree.deleteValue(20);
    cout << "Inorder after deletion: ";
    tree.inorder();

    cout << "Deleting 30\n";
    tree.deleteValue(30);
    cout << "Inorder after deletion: ";
    tree.inorder();

    cout << "Deleting 50\n";
    tree.deleteValue(50);
    cout << "Inorder after deletion: ";
    tree.inorder();

    return 0;
}