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

    public:
        stack<Node*>s; // for non-recursive traversals (backtracking)

        void inorderTraversalRecursive(Node* root){
            if (root != nullptr){
                inorderTraversalRecursive(root->left);
                cout << root->data;
                inorderTraversalRecursive(root->right);
            }
            else return;
        }

        void inorderTraversalNonRecursive(Node* root){
            while(root!=nullptr){
                s.push(root);
                root = root->left;
            }
            while(!s.empty()){
                root = s.top();
                s.pop();
                cout<<root->data;
                root = root->right;

                while(root!=nullptr){
                    s.push(root);
                    root = root->left;
                }
            }
        }

        void preorderTraversalRecursive(Node *root){
            if (root  != nullptr){
                cout<<root->data;
                preorderTraversalRecursive(root->left);
                preorderTraversalRecursive(root->right);
            }
            else return;
        }

        void preorderTraversalNonRecursive(Node *root){
            while(root!=nullptr){
                cout<<root->data;
                s.push(root);
                root = root->left;
            }
            while(!s.empty()){
                root = s.top();
                s.pop();
                root = root->right;

                while(root!=nullptr){
                    cout<<root->data;
                    s.push(root);
                    root = root->left;
                }
            }
        }

        void postorderTraversalRecursive(Node *root){
            if (root != nullptr){
                postorderTraversalRecursive(root->left);
                postorderTraversalRecursive(root->right);
                cout<<root->data;
            }
            else return;
        }

        Node* pre;
        bool flag = 0;
        void postorderTraversalNonRecursive(Node *root){
            while(root!=nullptr){
                s.push(root);
                root = root->left;
            }
            while(!s.empty()){
                root = s.top();
                flag = 0;

                if (root->right == pre || (root->right == nullptr) ){
                    cout<<root->data;
                    s.pop();
                    if(root->right == pre){
                        flag = 1;
                    }
                    pre = root;
                }
                root = root->right;

                while(root!=nullptr and flag == 0){
                    s.push(root);
                    root = root->left;
                }
            }
        }
};

int main(){
    int op = 1, op1 = 1;
    string postfix, prefix;

    ExpressionTree t;
    Node *root;

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
                root = st.top();
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
                root = st.top();
                st.pop();
                break;
            case 3:
                while(op1!=0){
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
                            t.inorderTraversalRecursive(root);
                            break;
                        case 2:
                            t.inorderTraversalNonRecursive(root);
                            break;
                        case 3:
                            t.preorderTraversalRecursive(root);
                            break;
                        case 4:
                            t.preorderTraversalNonRecursive(root);
                            break;
                        case 5:
                            t.postorderTraversalRecursive(root);
                            break;
                        case 6:
                            t.postorderTraversalNonRecursive(root);
                            break;
                        default:
                            op1 = 0;
                            break;
                    }
                }
                break;
            default:
                op = 0;
                break;
        }        
    }
}