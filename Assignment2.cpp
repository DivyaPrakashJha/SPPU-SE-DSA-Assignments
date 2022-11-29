#include<bits/stdc++.h>

using namespace std;
#define nl "\n"

map<char, int>m = {{'(', 6}, {'^', 5}, {'*', 4}, {'/', 3}, {'+', 2}, {'-', 1}};

class Node{
    public:
        char data;
        int data1;
        Node *next;
};

class Stack{ // Stack as an ADT
    Node *top;

    public:
        Stack(){
            top = NULL;
        }

        void push(char d){ // for characters
            Node *temp = new Node();
            temp->data = d;
            
            temp->next = top;
            top = temp;
        }

        void push1(int d){ // for integers
            Node *temp = new Node();
            temp->data1 = d;
            
            temp->next = top;
            top = temp;
        }

        char pop(){ // for characters
            if (top == NULL){
                return ' ';
            }
            else{ 
                Node *temp = top;
                top = top->next;

                char el = temp->data;
                free(temp);
                return el;
            }
        }

        int pop1(){ // for integers
            if (top == NULL){
                return 1;
            }
            else{ 
                Node *temp = top;
                top = top->next;

                int el = temp->data1;
                free(temp);
                return el;
            }
        }

        char tp(){ // for characters
            return top->data;
        }

        int tp1(){ // for integers
            return top->data1;
        }

        bool empty(){
            return top == NULL ? true : false;
        }

        void display(){ // for characters
            Node *temp = top;
            while(temp != NULL){
                cout<<temp->data<<nl;
                temp = temp->next;
            }
        }

        void display1(){ // for integers
            Node *temp = top;
            while(temp != NULL){
                cout<<temp->data1<<nl;
                temp = temp->next;
            }
        }    
};

string infixToPostfix(Stack &st, string infix){
    string postfix = "";

    for(auto it : infix){
        if ( (it >= 'a' and it <= 'z') or (it >= 'A' and it <= 'Z') or (it >= '0' and it <= '9')){
            postfix += it;
        }
        else if (it == '('){
            st.push(it);
        }
        else if (st.empty() and it == ')'){
            return "Invalid Expression";
        }
        else if (st.empty()){
            st.push(it);
        }
        else if (it == ')'){
                while(st.tp() != '('){
                    postfix += st.pop();
                }
                st.pop();
        }
        else{
            if(st.tp() == '('){
                st.push(it);
            }
            else if (m[it] >= m[st.tp()]){
                st.push(it);    
            }
            else if (m[it] < m[st.tp()]){
                while(!st.empty() and m[it] < m[st.tp()] and st.tp() != '('){
                    postfix += st.pop();
                }
                st.push(it);
            }            
        }

    }

    while(!st.empty()){
        if(st.tp() != '('){
            postfix += st.pop();
        }
        else{
            return "Invalid Expression";
        }
    }

    return postfix;
}

string infixToPrefix(Stack &st, string infix){
    string prefix = "";
    reverse(infix.begin(), infix.end());
    for(auto &it : infix){
        if (it == ')'){
            it = '(';
        }
        else if (it == '('){
            it = ')';
        }
    }

    prefix = infixToPostfix(st, infix);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int postfixEvaluation(Stack &st, string postfix, bool flag){
    
    for(auto it : postfix){
        if ((it >= 'a' and it <= 'z') or (it >= 'A' and it <= 'Z')){
            int temp;
            cout<<"Enter the value of "<<it<<" :";
            cin>>temp;
            st.push1(temp);
        }
        else if (it >= '0' and it <= '9'){
            st.push1(it - '0');
        }
        else{
            int a = 0, b = 0;

            if (flag){
                a = st.pop1();
                b = st.pop1();
            }
            else{
                b = st.pop1();
                a = st.pop1();
            }
            

            if (it == '^'){
                st.push1(pow(b, a));
            }
            else if (it == '/'){
                if(a == 0){
                    cout<<"Cannot divide by zero";
                    return 0;
                }
                st.push1(b/a);
            }
            else if (it == '*'){
                st.push1(b*a);
            }
            else if(it == '+'){
                st.push1(b+a);
            }
            else if(it == '-'){
                st.push1(b-a);
            }
        }
    }
    return st.tp1();
}

int prefixEvaluation(Stack &st, string prefix){
    reverse(prefix.begin(), prefix.end());

    return postfixEvaluation(st, prefix, 0);
}

int main(){
    Stack st;

    int op = 0;
    string infix, postfix, prefix;

    do{
        cout<<"\n*** Operations ***\n"
            <<"    1. Infix to postfix\n"
            <<"    2. Infix to prefix\n"
            <<"    3. Postfix Evaluation\n"
            <<"    4. Prefix Evaluation\n"
            <<"    0. Exit\n";

        cin>>op;

        switch(op){
            case 1:
                cout<<"Enter the Infix Expression : ";
                cin>>infix;
                
                cout<<"Postfix Expression : "<<infixToPostfix(st, infix);
                break;

            case 2:
                cout<<"Enter the Infix Expression : ";
                cin>>infix;

                cout<<"Prefix Expression : "<<infixToPrefix(st, infix);
                break;

            case 3:
                cout<<"Enter the Postfix Expression : ";
                cin>>postfix;
                cout<<postfixEvaluation(st, postfix, 1);
                break;
            case 4:
                cout<<"Enter the Prefix Expression : ";
                cin>>prefix;
                cout<<prefixEvaluation(st, prefix);
                break;
        }

        if(op == 3 or op == 4){
            st.pop1();
            while(!st.empty()){
                cout<<"Invalid Expression ";
                st.pop1();
            }
        }

    }while(op!=0);
}