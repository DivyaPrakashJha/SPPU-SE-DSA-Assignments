#include <bits/stdc++.h>

using namespace std;
#define nl "\n"
#define ht "\t"

class Students{
	private:
		int roll;
		string name;
		float sgpa;
		int ind;

	public:
		void putData(int a, string b, float c, int d){
			roll = a;
			name = b;
			sgpa = c;
			ind = d;
		}

		void getData(){
			cout<<"Index\tRoll\tName\t\tSGPA\n";
			cout<<ind<<ht<<roll<<ht<<name<<ht<<ht<<sgpa<<nl;
		}

		void linearSearch(Students s[], int n, float sg){
			int i = 0, flag = 0;
			for(i = 0; i < n; i++){
				if (s[i].sgpa == sg){
					flag = 1;
					s[i].getData();
				}
			}
			if (!flag) cout<<"NOT FOUND!\n";
		}

		void binarySearch(Students s[], int n, string nm){
			bubbleSort1(s, n);
			bool flag = 0;
			int low = 0, high = n-1, mid = (low+high)/2;
			
			while(low<=high){
				mid = (low+high)/2;

				if (s[mid].name == nm){
					flag = 1;
					s[mid].getData();
					break;
				}
				else if (nm < s[mid].name){
					high = mid - 1;
				}
				else{
					low = mid + 1;
				}
			}
			if (!flag){
				cout<<"NOT FOUND!\n"; 
			}
		}

		void bubbleSort(Students s[], int n){ // for integers
			for(int i = 1; i < n; i++){
				for(int j = 0; j < n-i; j++){
					if (s[j].roll > s[j+1].roll){
						swap(s[j], s[j+1]);
					}
				}
			}
		}

		void bubbleSort1(Students s[], int n){ // for strings
			for(int i = 1; i < n; i++){
				for(int j = 0; j < n-i; j++){
					if (s[j].name > s[j+1].name){
						swap(s[j], s[j+1]);
					}
				}
			}
		}

		void insertionSort(Students s[], int n, Students temp){
			for(int i = 1; i < n; i++){
				temp = s[i];
				int j = i-1;
				while(j >= 0 && s[j].name > temp.name){
					s[j+1] = s[j];
					j--;
				}
				s[j+1] = temp;
			}
		}

		

		int partition (Students arr[], int low, int high){
			int i = low;
			int j = high;
			float pivot = arr[low].sgpa;

			while(i<j){
				while(arr[i].sgpa <= pivot){
					i++;
				}
				while(arr[j].sgpa > pivot){
					j--;
				}
				
				if(i<j){
					swap(arr[i], arr[j]);
				}
			}

			swap(arr[j], arr[low]);
			return j;
		}

		void quickSort(Students arr[], int low, int high) { 
    		if (low < high) { 
        		int p = partition(arr, low, high); 
        		quickSort(arr, low, p - 1); 
        		quickSort(arr, p + 1, high); 
    		} 
		} 
		
};

int main(){
	
	int n = 30;
	Students s[n], p;

	int op = 0, dt=0, r;
	float sg;
	string nm;

	do{
		cout<<"\n****Functions**** \n"
			<<"Select the desired option : \n"
			<<"1. Take input\n"
			<<"2. Display data\n"
			<<"3. Search by SGPA (Linear Search)\n"
			<<"4. Search by Name (Binary Search)\n"
			<<"5. Sort by Roll Number (Bubble Sort)\n"
			<<"6. Sort by Name (Insertion Sort)\n"
			<<"7. Sort by SGPA (Quick Sort)\n"
			<<"0. Exit\n";

		cin>>op;

		if (op>7){
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
				cout<<"Enter the number of students: ";
				cin>>n;

				for(int i = 0; i < n; i++){
					cout<<"Enter the roll number of student : ";
					cin>>r;	
					cout<<"Enter the name of student : ";
					cin>>nm;	
					cout<<"Enter the sgpa of student : ";
					cin>>sg;

					s[i].putData(r, nm, sg, i);
				}
				break;

			case 2:
				for(int i = 0; i < n; i++){
					s[i].getData();
					cout<<nl;
				}
				break;

			case 3:
				cout<<"Enter the SGPA of student you want to search for : ";
				cin>>sg;
				p.linearSearch(s, n, sg);
				break;

			case 4:
				cout<<"Enter the name of student you want to search for : ";
				cin>>nm;
				p.binarySearch(s, n, nm);
				break;

			case 5:
				p.bubbleSort(s, n);
				cout<<"Student details sorted according to the Roll numbers:\n";
				for(int i = 0; i < n; i++){
					s[i].getData();
					cout<<nl;
				}
				break;

			case 6:
				p.insertionSort(s, n, p);
				cout<<"Student details sorted according to the names:\n";
				for(int i = 0; i < n; i++){
					s[i].getData();
					cout<<nl;
				}
				break;

			case 7:
				p.quickSort(s, 0, n-1);
				cout<<"How many students do you want to see?\n";
				int a;
				cin>>a;
				if (a>n) cout<<"Enter valid input!!";
				else{
					for(int i = n-1; i >= n-a; i--){
						s[i].getData();
						cout<<nl;
					}
				}
				break;
				
		}
	}while (op);

	return 0;
}
