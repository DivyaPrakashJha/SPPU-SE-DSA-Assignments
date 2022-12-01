#include <bits/stdc++.h>

using namespace std;
#define nl "\n"

class Node{
    public:
        int data;
        bool lbit, rbit;
        Node *left, *right;

    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
        lbit = 0;
        rbit = 0;
    }
};

void insert1(Node *root, Node *&p){
    if (p->data == root->data){
        cout<<"T-BST cannot contain duplicate elements";
        return; 
    }
    else if (p->data < root->data){
        if (root->lbit == 0){
            p->left = root->left; // Dangling pointer from p
            
            root->left = p;
            root->lbit =  1;
            
            p->right = root;
        }
        else{
            insert1(root->left, p);
        }
    }
    else if (p->data > root->data){
        if (root->rbit == 0){
            p->right = root->right; // Dangling pointer from p
            
            root->right = p;
            root->rbit = 1;
            
            p->left = root;
        }
        else{
            insert1(root->right, p);
        }
    }
}

class ThreadedBST{
    Node *head, *root;

    public:
        ThreadedBST(){
            head = new Node(999);
            root = nullptr;
            head->right = head;
            head->rbit = 1;
        }

        void insert(int data){
            Node *p = new Node(data);

            if (root == nullptr){
                root = p;
                head->left = root;
                head->lbit = 1;
                p->left = head;
                p->right = head;
            }
            else{
                insert1(root, p);
            }
        }

        void inorderTraversal(){
            Node *p = root;

            while(p != head){
                while(p->lbit != 0){
                    p = p->left;
                }
                cout<<p->data<<" ";
                while(p->rbit == 0){
                    p = p->right;
                    if (p!=head){
                        cout<<p->data<<" ";
                    }
                }
                p= p->right;
            }
        }

        void preorderTraversal(){
            Node *p = root;
            
            while(p!=head){
                while(p->lbit!=0){
                    cout<<p->data<<" ";
                    p = p->left;
                }
                cout<<p->data<<" ";

                while(p->rbit == 0){
                    p = p->right;
                }
                p = p->right;

            }
        }

};

int main(){
    ThreadedBST t;
    int op = 1, data = 0;

    do{
        cout<<"\n<---- Threaded BST ---->"<<nl<<nl;
        cout<<"Choose the desired option : "<<nl;
        cout<<"1. Insert Element"<<nl;
        cout<<"2. Inorder Traversal"<<nl;
        cout<<"3. Preorder Traversal"<<nl;
        cout<<"0. Exit"<<nl;

        cin>>op;

        switch (op){
            case 1:
                cout<<"Enter the element you want to insert : ";
                cin>>data;

                t.insert(data);
                break;
            case 2:
                t.inorderTraversal();
                break;
            case 3:
                t.preorderTraversal();
                break;
            default:
                op = 0;
                break;
        }
    }while(op!=0);
}