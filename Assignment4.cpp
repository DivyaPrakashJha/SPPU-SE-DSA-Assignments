#include<bits/stdc++.h>

using namespace std;
#define nl "\n"

class Node{
    public:
        Node* left;
        char data;
        Node* right;

        Node(char x){
            data = x;
            left = nullptr;
            right = nullptr;
        }
};

class ExpressionTree{
    Node *root;

    public:
        ExpressionTree(){
            root = nullptr;
        }

        void setRoot(Node* r){
            root = r;
        }

        Node* getRoot(){
            return root;
        }

        stack<Node*>s; // for non-recursive traversals (backtracking)

        void inorderTraversalRecursive(Node* root1){
            if (root1 != nullptr){
                inorderTraversalRecursive(root1->left);
                cout << root1->data;
                inorderTraversalRecursive(root1->right);
            }
            else return;
        }

        void inorderTraversalNonRecursive(Node* root1){
            while(root1!=nullptr){
                s.push(root1);
                root1 = root1->left;
            }
            while(!s.empty()){
                root1 = s.top();
                s.pop();
                cout<<root1->data;
                root1 = root1->right;

                while(root1!=nullptr){
                    s.push(root1);
                    root1 = root1->left;
                }
            }
        }

        void preorderTraversalRecursive(Node *root1){
            if (root1  != nullptr){
                cout<<root1->data;
                preorderTraversalRecursive(root1->left);
                preorderTraversalRecursive(root1->right);
            }
            else return;
        }

        void preorderTraversalNonRecursive(Node *root1){
            while(root1!=nullptr){
                cout<<root1->data;
                s.push(root1);
                root1 = root1->left;
            }
            while(!s.empty()){
                root1 = s.top();
                s.pop();
                root1 = root1->right;

                while(root1!=nullptr){
                    cout<<root1->data;
                    s.push(root1);
                    root1 = root1->left;
                }
            }
        }

        void postorderTraversalRecursive(Node *root1){
            if (root1 != nullptr){
                postorderTraversalRecursive(root1->left);
                postorderTraversalRecursive(root1->right);
                cout<<root1->data;
            }
            else return;
        }

        Node* pre;
        bool flag = 0;
        void postorderTraversalNonRecursive(Node *root1){
            while(root1!=nullptr){
                s.push(root1);
                root1 = root1->left;
            }
            while(!s.empty()){
                root1 = s.top();
                flag = 0;

                if (root1->right == pre || (root1->right == nullptr) ){
                    cout<<root1->data;
                    s.pop();
                    if(root1->right == pre){
                        flag = 1;
                    }
                    pre = root1;
                }
                root1 = root1->right;

                while(root1!=nullptr and flag == 0){
                    s.push(root1);
                    root1 = root1->left;
                }
            }
        }
};

int main(){
    int op = 1, op1 = 1;
    string postfix, prefix;

    ExpressionTree t;

    stack<Node*>st;
    
    while(op!=0){
        cout<<"\nChoose the operation you want to perform: "<<nl;
        cout<<"1. Postfix Expression Tree"<<nl;
        cout<<"2. Prefix Expression Tree"<<nl;
        cout<<"3. Traversal"<<nl;
        cout<<"*. Press any other numeric key to exit"<<nl;
        cin>>op;

        switch(op){
            case 1:
                cout<<"Enter the Postfix Expression : "<<nl;
                cin>>postfix;

                for(auto it : postfix){
                    Node *newNode = new Node(it);
                    if ((it >= 'a' and it <= 'z') or (it >= 'A' and it <= 'Z') or (it >= '0' and it <= '9')){
                        st.push(newNode);
                    }
                    else{
                        Node *t2 = st.top();
                        st.pop();
                        Node *t1 = st.top();
                        st.pop();
                        newNode->left = t1;
                        newNode->right = t2;
                        st.push(newNode);
                    }
                }
                t.setRoot(st.top());
                st.pop();
                break;
            case 2:
                cout<<"Enter the Prefix Expression : "<<nl;
                cin>>prefix;

                for(auto it = prefix.rbegin(); it < prefix.rend(); it++){
                    Node *newNode = new Node(*it);
                    if ((*it >= 'a' and *it <= 'z') or (*it >= 'A' and *it <= 'Z') or (*it >= '0' and *it <= '9')){
                        st.push(newNode);
                    }
                    else{
                        Node *t1 = st.top();
                        st.pop();
                        Node *t2 = st.top();
                        st.pop();
                        newNode->left = t1;
                        newNode->right = t2;
                        st.push(newNode);
                    }
                }
                t.setRoot(st.top());
                st.pop();
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
                            t.inorderTraversalNonRecursive(t.getRoot());
                            break;
                        case 3:
                            t.preorderTraversalRecursive(t.getRoot());
                            break;
                        case 4:
                            t.preorderTraversalNonRecursive(t.getRoot());
                            break;
                        case 5:
                            t.postorderTraversalRecursive(t.getRoot());
                            break;
                        case 6:
                            t.postorderTraversalNonRecursive(t.getRoot());
                            break;
                        default:
                            op1 = 0;
                            break;
                    }
                }while(op1!=0);
                break;
            default:
                op = 0;
                break;
        }        
    }
}