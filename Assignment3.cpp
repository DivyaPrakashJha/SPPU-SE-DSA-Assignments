#include <bits/stdc++.h>

using namespace std;

void insertElement(int q[], int n, int &f, int &r, int data){
    if (f == -1 and r == -1){
        f++;
        r++;
        q[r] = data;
    }
    else if ((r+1)%n == f){
        cout<<"Circular Queue is full!\n";
    }
    else{
        r = (r+1)%n;
        q[r] = data;
    }
}

void deleteElement(int q[], int n, int &f, int &r){
    if (f == -1 and r == -1){
        cout<<"Circular queue is already empty\n";
    }
    else if (f == r){
        cout<<"The deleted data is "<<q[f]<<endl;
        f = -1;
        r = -1;
    }
    else{
        cout<<"The deleted data is "<<q[f]<<endl;
        f = (f+1)%n;
    }
}

void display(int q[], int n, int f, int r){
    if (f == -1 and r == -1){
        cout<<"Circular Queue is empty\n";
    }
    else{
        cout<<"The elements of Circular queue are : ";
        while(f != r){
            cout<<q[f]<<" ";

            f = (f+1)%n;
        }
        cout<<q[f]<<endl;
    }
}

int main(){
    int n;
    cout<<"\nEnter the size of the Circular queue : ";
    cin>>n;

    int q[n];
    int f = -1, r = -1, data = 0;

    bool run = 1;
    int op = 0;
    while(run){
        cout<<"**** CIRCULAR QUEUE ****\n\n"
            <<"Choose the desired option : \n"
            <<"1. Insertion (Enqueue)\n"
            <<"2. Deletion (Dequeue)\n"
            <<"3. Display the Circular Queue\n"
            <<"4. Enter any other numeric key to exit\n\n";

        cin>>op;
        
        switch(op){
            case 1:
                cout<<"Enter the data you want to insert : ";
                cin>>data;
                insertElement(q, n, f, r, data);
                break;
            case 2:
                deleteElement(q, n , f, r);
                break;
            case 3:
                display(q, n, f, r);
                break;
            default:
                run = 0;            
        }
    }    
}