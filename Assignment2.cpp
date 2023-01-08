#include<bits/stdc++.h>

using namespace std;
#define nl "\n"

map<char, int>precedence = { {'^', 5}, {'*', 4}, {'/', 3}, {'+', 2}, {'-', 1} };


template<class T>
class Node{
    public:
        T data;
        Node *next;

        Node(T x){
            data = x;
            next = nullptr;
        }
};

template<class T>
class Stack{ // Stack as an ADT
    Node<T> *top;

    public:
        Stack(){
            top = nullptr;
        }

        void push(T d){
            Node<T> *temp = new Node<T>(d);
            
            temp->next = top;
            top = temp;
        }

        void pop(){
            if (top == nullptr){
                return;
            }
            else{ 
                Node<T> *temp = top;
                top = top->next;

                free(temp);
            }
        }

        T tp(){
            return top->data;
        }

        bool empty(){
            return (top == nullptr) ? true : false;
        }

        void display(){
            Node<T> *temp = top;
            while(temp != nullptr){
                cout<<temp->data<<nl;
                temp = temp->next;
            }
        }    
};

string infixToPostfix(string infix){
    Stack<char> st;
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
        else if (st.tp() == '('){
            st.push(it);
        }
        else if (it == ')'){
                while(st.tp() != '('){
                    postfix += st.tp();
                    st.pop();
                }
                st.pop();
        }
        else{
            if (precedence[it] >= precedence[st.tp()]){
                st.push(it);    
            }
            else if (precedence[it] < precedence[st.tp()]){
                while(!st.empty() and st.tp() != '(' and precedence[it] < precedence[st.tp()] ){
                    postfix += st.tp();
                    st.pop();
                }
                st.push(it);
            }            
        }

    }

    while(!st.empty()){
        if(st.tp() != '('){
            postfix += st.tp();
            st.pop();
        }
        else{
            return "Invalid Expression";
        }
    }

    return postfix;
}

string infixToPrefix(string infix){
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

    prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int postfixEvaluation(string postfix, bool flag){ // flag = 1 (Used for postfix evaluation), flag = 0 (Used for prefix evaluation)
    Stack<int>st;
    
    for(auto it : postfix){
        if ((it >= 'a' and it <= 'z') or (it >= 'A' and it <= 'Z')){
            int temp;
            cout<<"Enter the value of "<<it<<" :";
            cin>>temp;
            st.push(temp);
        }
        else if (it >= '0' and it <= '9'){
            st.push(it - '0');
        }
        else{
            int a = 0, b = 0;

            if (flag){
                a = st.tp(); st.pop();
                b = st.tp(); st.pop();
            }
            else{
                b = st.tp(); st.pop();
                a = st.tp(); st.pop();
            }
            

            if (it == '^'){
                st.push(pow(b, a));
            }
            else if (it == '/'){
                if(a == 0){
                    cout<<"Cannot divide by zero";
                    return 0;
                }
                st.push(b/a);
            }
            else if (it == '*'){
                st.push(b*a);
            }
            else if(it == '+'){
                st.push(b+a);
            }
            else if(it == '-'){
                st.push(b-a);
            }
        }
    }
    
    int ev = st.tp();

    st.pop();
    if(!st.empty()){
        cout<<"Invalid Expression ";
    }

    return ev;
}

int prefixEvaluation(string prefix){
    reverse(prefix.begin(), prefix.end());

    return postfixEvaluation(prefix, 0);
}

int main(){

    int op = 0;
    string infix, postfix, prefix;

    do{
        cout<<"\n\n********** Operations **********\n"
            <<"    1. Infix to postfix\n"
            <<"    2. Infix to prefix\n"
            <<"    3. Postfix Evaluation\n"
            <<"    4. Prefix Evaluation\n"
            <<"    0. Exit\n"
            <<"**********************************\n";
        cin>>op;

        switch(op){
            case 1:
                cout<<"Enter the Infix Expression : ";
                cin>>infix;
                
                cout<<"Postfix Expression : "<<infixToPostfix(infix);
                break;

            case 2:
                cout<<"Enter the Infix Expression : ";
                cin>>infix;

                cout<<"Prefix Expression : "<<infixToPrefix(infix);
                break;

            case 3:
                cout<<"Enter the Postfix Expression : ";
                cin>>postfix;
                cout<<postfixEvaluation(postfix, 1);
                break;
            case 4:
                cout<<"Enter the Prefix Expression : ";
                cin>>prefix;
                cout<<prefixEvaluation(prefix);
                break;
        }

    }while(op!=0);
}