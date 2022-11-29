#include <bits/stdc++.h>

using namespace std;
#define nl "\n"

class Node{
    public:
        Node *left;
        int data;
        Node *right;

    Node(int x){
        left = nullptr;
        data = x;
        right = nullptr;
    }
};

class BST{
    Node* root = nullptr;

    public:
        Node* getRoot(){
            return root;
        }
        void setRoot(Node* root){
            this->root = root;
        }

        void insert(int x){
            Node *r = new Node(x);
        
            if (root == nullptr){
                root = r;
            }
            else{
                Node *p = root, *q = nullptr;
                while(p!=nullptr){
                    q = p;
                    if (x == p->data){
                        cout<<"BST cannot contain duplicate elements\n";
                        return;
                    }
                    else if (x > p->data){
                        p = p->right;
                    }
                    else{
                        p = p->left;
                    }
                }
                if (x > q->data){
                    q->right = r;
                }
                else{
                    q->left = r;
                }
            }
        }

        void del(int x){
            Node *p = root, *q = nullptr;
            if (p == nullptr){
                cout<<"The tree is empty";
                return;
            }

            while(p!=nullptr){
                if (x < p->data){
                    q = p;   
                    p = p->left;
                }
                else if (x > p->data){
                    q = p;
                    p = p->right;
                }
                else{
                    break;
                }
            }

            if (p == nullptr){
                cout<<"Element Not Found!!";
            }
            else if (p->left == nullptr and p->right == nullptr){ // For leaf Nodes
                if (q->left == p){
                    q->left = nullptr;
                    free(p);
                } 
                else if (q->right == p) {
                    q->right = nullptr;
                    free(p);
                }
            }
            else if (p->left == nullptr or p->right == nullptr){ // For nodes having single child
                if (q->left == p){
                    if (p->left == nullptr){
                        q->left = p->right;
                        free(p);   
                    }
                    else if (p->right == nullptr){
                        q->left = p->left;
                        free(p);
                    }
                }
                else if (q->right == p){
                    if (p->left == nullptr){
                        q->right = p->right;
                        free(p);
                    }
                    else if (p->right == nullptr){
                        q->right = p->left;
                        free(p);
                    }
                }
            }
            else if (p->left != nullptr and p->right != nullptr){ // For nodes having two children
                Node *mnRight = min(p->right);
                int mnData = mnRight->data;
                
                del(mnRight->data); // Either a leaf node or a node with single child
                p->data = mnData;
            }
        }

        // Traversals

        stack<Node*>s;
        
        void inorderTraversalRecursive(Node* root1){
            if (root1 != nullptr){
                inorderTraversalRecursive(root1->left);
                cout << root1->data<<" ";
                inorderTraversalRecursive(root1->right);
            }
        }

        void inorderTraversalNonRecursive(){
            Node *root1 = root;
            while(root1!=nullptr){
                s.push(root1);
                root1 = root1->left;
            }
            while(!s.empty()){
                root1 = s.top();
                s.pop();
                cout<<root1->data<<" ";
                root1 = root1->right;

                while(root1!=nullptr){
                    s.push(root1);
                    root1 = root1->left;
                }
            }
        }

        void preorderTraversalRecursive(Node *root1){
            if (root1 != nullptr){
                cout<<root1->data<<" ";
                preorderTraversalRecursive(root1->left);
                preorderTraversalRecursive(root1->right);
            }
        }

        void preorderTraversalNonRecursive(){
            Node *root1 = root;
            while(root1!=nullptr){
                cout<<root1->data<<" ";
                s.push(root1);
                root1 = root1->left;
            }
            while(!s.empty()){
                root1 = s.top();
                s.pop();
                root1 = root1->right;

                while(root1!=nullptr){
                    cout<<root1->data<<" ";
                    s.push(root1);
                    root1 = root1->left;
                }
            }
        }

        void postorderTraversalRecursive(Node *root1){
            if (root1 != nullptr){
                postorderTraversalRecursive(root1->left);
                postorderTraversalRecursive(root1->right);
                cout<<root1->data<<" ";
            }
        }

        Node* pre;
        bool flag = 0;
        void postorderTraversalNonRecursive(){
            Node *root1 = root;
            while(root1 != nullptr){
                s.push(root1);
                root1 = root1->left;
            }
            while(!s.empty()){
                root1 = s.top();
                flag = 0;

                if (root1->right == nullptr || (root1->right == pre) ){
                    cout<<root1->data<<" ";
                    s.pop();
                    if(root1->right == pre){
                        flag = 1;
                    }
                    pre = root1;
                }
                root1 = root1->right;

                while(root1 != nullptr and flag == 0){
                    s.push(root1);
                    root1 = root1->left;
                }
            }
        }

        void mirrorImage(Node *root1){
            if (root1 == nullptr){
                return;
            }
            else{
                mirrorImage(root1->left);
                mirrorImage(root1->right);

                swap(root1->left, root1->right);
            }
        }

        void displayLeafNode(){
            Node *p = root;

            while(p!=nullptr){
                s.push(p);
                p = p->left;
            }
            while(!s.empty()){
                p = s.top();
                s.pop();
                if (p->left == nullptr and p->right == nullptr){
                    cout<<p->data<<" ";
                }
                p = p->right;

                while(p!=nullptr){
                    s.push(p);
                    p = p->left;
                }
            }
            
        }

        int heightBST(){
            int height = 0;
            queue<Node*>q;

            if (root == nullptr){
                return 0;
            }

            Node *p = root;
            q.push(p);
            q.push(nullptr);

            while(!q.empty()){
                Node *temp = q.front();
                q.pop();

                if (temp == nullptr){
                    height++;
                    if (!q.empty()){
                        q.push(nullptr);
                    }
                }
                else{
                    if (temp->left != nullptr){
                        q.push(temp->left);
                    }
                    if (temp->right != nullptr){
                        q.push(temp->right);
                    }
                }
            }

            return height-1;
        }

        Node* min(Node *root1){
            while(root1->left != nullptr){
                root1 = root1 -> left;
            }
            return root1;
        }

        Node* max(Node *root1){
            while(root1->right != nullptr){
                root1 = root1 -> right;
            }
            return root1;
        }

        bool search(int x){
            Node *p = root;
            while(p!=nullptr){
                if (x == p->data){
                    return 1;
                }
                else if (x < p->data){
                    p = p->left;
                }
                else{
                    p = p->right;
                }
            }
            return 0;
        }

        void levelWiseDisplay(){
            queue<Node*>q;

            if (root == nullptr){
                cout<<"Empty";
            }

            Node *p = root;
            q.push(p);
            q.push(nullptr);

            while(!q.empty()){
                Node *temp = q.front();
                q.pop();

                if (temp == nullptr){
                    cout<<nl;
                    if (!q.empty()){
                        q.push(nullptr);
                    }
                }
                else{
                    cout<<temp->data<<" ";
                    if (temp->left != nullptr){
                        q.push(temp->left);
                    }
                    if (temp->right != nullptr){
                        q.push(temp->right);
                    }
                }
            }

            
        }
};

int main(){
    BST t;
    BST copy;
    int op = 1, op1 = 1, x;

    while(op!=0){
        cout<<"\n*******************************************"
            <<"\n\nChoose the operation you want to perform : "<<nl
            <<" 1. Insertion"<<nl
            <<" 2. Deletion"<<nl
            <<" 3. Display"<<nl
            <<" 4. Mirror Image"<<nl
            <<" 5. Copy"<<nl
            <<" 6. Display the Leaf Node"<<nl
            <<" 7. Height of BST"<<nl
            <<" 8. Find minimum"<<nl
            <<" 9. Find maximum"<<nl
            <<"10. Search"<<nl
            <<"11. Level-Wise Display"<<nl
            <<" 0. Exit"<<nl;

            cin>>op;

            switch(op){
                case 1:
                    cout<<"Enter the data you want to insert :";
                    cin>>x;
                    t.insert(x);
                    break;

                case 2:
                    cout<<"Enter the value you want to delete :";
                    cin>>x;
                    t.del(x);
                    break;

                case 3:
                    do{
                        cout<<"\n\nChoose the desired traversal technique : "<<nl;
                        cout<<"1. Inorder Traversal(Recursive)"<<nl;
                        cout<<"2. Inorder Traversal(Non-Recursive)"<<nl;
                        cout<<"3. Preorder Traversal(Recursive)"<<nl;
                        cout<<"4. Preorder Traversal(Non-Recursive)"<<nl;
                        cout<<"5. Postorder Traversal(Recursive)"<<nl;
                        cout<<"6. Postorder Traversal(Non-Recursive)"<<nl;
                        cout<<"*. Press any other numeric key to go to the main menu"<<nl;
                        cin>>op1;
                        switch(op1){
                            case 1:
                                t.inorderTraversalRecursive(t.getRoot());
                                break;
                            case 2:
                                t.inorderTraversalNonRecursive();
                                break;
                            case 3:
                                t.preorderTraversalRecursive(t.getRoot());
                                break;
                            case 4:
                                t.preorderTraversalNonRecursive();
                                break;
                            case 5:
                                t.postorderTraversalRecursive(t.getRoot());
                                break;
                            case 6:
                                t.postorderTraversalNonRecursive();
                                break;
                            default:
                                op1 = 0;
                                break;
                        }
                    }while(op1!=0);
                    break;

                case 4:
                    t.mirrorImage(t.getRoot());
                    cout<<"The binary tree is not a BST anymore!!"
                        <<nl<<"If you want to make it a BST, Mirror it again!!";
                    break;

                case 5:
                    copy.setRoot(t.getRoot());
                    copy.inorderTraversalRecursive(copy.getRoot());
                    break;

                case 6:
                    cout<<"Leaf Nodes : ";
                    t.displayLeafNode();
                    break;

                case 7:
                    cout<<"Height : "<<t.heightBST();
                    break;

                case 8:
                    cout<<"The minimum value : "<<t.min(t.getRoot())->data;
                    break;

                case 9:
                    cout<<"The maximum value : "<<t.max(t.getRoot())->data;
                    break;

                case 10:
                    cout<<"Enter the value you want to search for in the BST: ";
                    cin>>x;
                    t.search(x) ? cout<<"Value Found" : cout<<"Value Not Found";
                    break;

                case 11:
                    cout<<"Level wise display"<<nl;
                    t.levelWiseDisplay();
                    break;

                default:
                    op = 0;
                    break;
            }
    }
}