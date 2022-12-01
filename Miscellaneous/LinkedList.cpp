#include <bits/stdc++.h>

using namespace std;
#define nl "\n"

class Node{
    public:
        int data;
        Node *next;
};

class LL{
    Node *head;

    public:
        LL(){
            head = nullptr;
        }

        void insertNodeFront(int d){
            Node *newNode = new Node();
            newNode->data = d;

            newNode->next = head;
            head = newNode;
        }

        void insertNodeBack(int d){
            Node *newNode = new Node();
            newNode->data = d;
            newNode->next = nullptr;

            if (head == nullptr){
                head = newNode;
            }
            else{
                Node *temp = head;
                while(temp->next!=nullptr){
                    temp = temp -> next;
                }
                temp->next = newNode;
            }
        }

        void insertNodeAfter(int d, int key){
            Node *temp = head;

            while(temp->data != key){
                temp = temp->next;
            }
            if (temp != nullptr){
                Node *newNode = new Node();
                newNode -> data = d;
                Node *p = temp->next;
                temp->next = newNode;
                newNode->next = p; 
            }
            else{
                cout<<"Key not found!";
            }
        }

        void deleteNodeFront(){
            if (head == nullptr){
                cout<<"The linked list is empty!";
            }
            else{
                Node *temp = head; // storing the pointer to the curr head to free up memory acquired by it
                head = head->next; // moving the head pointer one link ahead
                free(temp); // releasing the acquired memory (can also use "delete temp")
            }
        }

        void deleteNodeBack(){
            if (head == nullptr){
                cout<<"The linked list is empty!";
            }
            else{
                Node *end = head, *secLast = nullptr;
                while(end->next != nullptr){
                    secLast = end;
                    end = end->next;
                }
                secLast->next = nullptr;
                free(end);
            }

        }

        void deleteNode(int key){
            Node *temp = head;
            while(temp->next->data != key){
                temp = temp->next;
            }
            if (temp->next != nullptr){
                Node *temp1 = temp->next;
                temp->next = temp1->next;
            }
            else{
                cout<<"Key not found!";
            }
        }

        void reverseLinkedList(){
            Node *curr = head;
            Node *prev = nullptr;
            Node *nex = nullptr;

            while(curr != nullptr){
                nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
            }
            head = prev;
        }

        void displayLinkedList(){
            if (head == nullptr){
                cout<<"Empty";
            }
            Node *temp = head;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }


};

int main(){
    int op = 0, dt = 0, op1 = 0;
    LL d;
    
    int data = 0, key = 0;

    cout<<"++++++ SINGLY LINKED LIST ++++++\n";
    do{
		cout<<"\n**** Functions **** \n"
			<<"Select the desired option : \n"
            <<"1. Create a Linked List\n"
			<<"2. Insert a Node\n"
			<<"3. Delete a Node\n"
            <<"4. Reverse the Linked List\n"
			<<"5. Display the Linked List\n"
			<<"0. Exit\n";
        cin>>op;

		if (op>5){
			cout<<"Wrong input!! Try again..\n";
			continue;
		}
		else if (dt == 0 && op != 1 ){
			cout<<"Please give input first!!\n";
			continue;
		}

        switch(op){
            case 1:
                dt = 1;
                cout<<"Linked List Created Successfully..\n";
                break;
            case 2:
                do{
                    cout<<"\n**** Node Insertion **** \n"
                    <<"Select the desired option : \n"
                    <<"1. Insert a Node at the beginning\n"
			        <<"2. Insert a Node at the end\n"
			        <<"3. Insert a Node at a position\n"
                    <<"*. Press any other numeric key to go to the Main Menu\n";

                    cin>>op1;

                    switch(op1){
                        case 1:
                            cout<<"Enter the data you want to insert : ";
                            cin>>data;
                            d.insertNodeFront(data);
                            break;
                        case 2:
                            cout<<"Enter the data you want to insert : ";
                            cin>>data;
                            d.insertNodeBack(data);
                            break;
                        case 3:
                            cout<<"Enter the data you want to insert : ";
                            cin>>data;
                            cout<<"Enter the element after which you want to insert the Node : ";
                            cin>>key;
                            d.insertNodeAfter(data, key);
                            break;
                        default:
                            op1 = 0;
                            break;
                    }
                }while(op1 != 0);
                
                break;

            case 3:
                do{
                    cout<<"\n**** Node Deletion **** \n"
                        <<"Select the desired option : \n"
                        <<"1. Delete the beginning Node\n"
			            <<"2. Delete the last Node\n"
			            <<"3. Delete a particular Node\n"
                        <<"0. Press any other numeric key to go to the Main Menu\n";

                        cin>>op1;

                        switch(op1){
                            case 1:
                                d.deleteNodeFront();
                                break;
                            case 2:
                                d.deleteNodeBack();
                                break;
                            case 3:
                                cout<<"Enter the Node value which you want to delete : ";
                                cin>>key;
                                d.deleteNode(key);
                                break;
                            default:
                                op1 = 0;
                                break;
                        }
                }while(op1 != 0);
                
                break;

            case 4:
                    d.reverseLinkedList();
                    cout<<"\nLinked List Reversed Successfully..\n";
                    break;

            case 5:
                    cout<<nl;
                    d.displayLinkedList();
                    break;
        }
    }while(op);
}

