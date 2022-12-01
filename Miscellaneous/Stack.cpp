#include<bits/stdc++.h>

using namespace std;
#define nl "\n"

class Node{ // For linked list elementation of stack
    public:
        int data;
        Node *next;
};

class Stack{ // Stack as an ADT
    Node *top;

    public:
        Stack(){
            top = NULL;
        }

        void push(int d){
            Node *temp = new Node();
            temp->data = d;
            
            temp->next = top;
            top = temp;
        }

        void pop(){
            if (top == NULL){
                cout<<"The stack is empty!\n";
            }
            else{
                Node *temp = top;
                top = top->next;

                int el = temp->data;
                free(temp);
                cout<<"The element popped : "<<el<<nl;
            }
        }

        bool empty(){
            return top == NULL ? true : false;
        }

        void display(){
            Node *temp = top;
            while(temp != NULL){
                cout<<temp->data<<nl;
                temp = temp->next;
            }
        }    
};

int main(){
    Stack st;

    int op = 0, data = 0;
    do{
        cout<<"\n*** Stack Operations ***\n"
            <<"    1. Push\n"
            <<"    2. Pop\n"
            <<"    3. Empty\n"
            <<"    4. Display\n"
            <<"    0. Exit\n";

        cin>>op;

        switch(op){
            case 1:
                cout<<"Enter the element you want to push : ";
                cin>>data;
                st.push(data);
                break;
            case 2:
                st.pop();
                cout<<nl;
                break;
            case 3: 
                st.empty() ? cout<<"The stack is Empty\n\n" : cout<<"The stack is not Empty\n\n";
                break;
            case 4:
                cout<<nl;
                st.display();
                break;
        }
    }while(op!=0);
}