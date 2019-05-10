#include <bits/stdc++.h>
using namespace std;

void createMaxHeap(std::vector<int> &v,int n);
void addElement(std::vector<int> &v,int *n);
void heapSortIncreasing(std::vector<int> &v,int n);
void heapSortDecreasing(std::vector<int> &v,int n);
void deleteElement(std::vector<int> &v,int *n);
void maxHeapify(std::vector<int> &v,int i, int n);
void printElements(std::vector<int> v);
void clearElements(std::vector<int> &v,int *n);
main(){
	int n;
	cin>>n;
	std::vector<int> v;
	for(int i=0;i<n;i++){
		int vi;
		cin>>vi;
		v.push_back(vi);
	}
	int cases;
	
	int flag=1;
	while(flag){
		cout<<"Enter Case :";
		cin>>cases;
	switch(cases){
		case 1:
			createMaxHeap(v,n);
			break;
		case 2:
			addElement(v,&n);
			break;
		case 3:
			heapSortIncreasing(v,n);
			break;
		case 4:
			heapSortDecreasing(v,n);
			break;
		case 5:
			deleteElement(v,&n);
			break;
		case 6:
			printElements(v);
			break;
		case 7:
			clearElements(v,&n);
			cout<<"\n"<<n<<"\n";
		case 0:
			flag=0;
			break;
		default:
			cout<<"Wrong input\n";
			break;
		}
	}	
}

void maxHeapify(std::vector<int> &v,int i, int n){
	int largest;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n&&v[l]>v[i]){
		largest=l;
	}else{
		largest=i;
	}
	if(r<n&&v[r]>v[largest]){
		largest=r;
	}
	if(largest!=i){
		iter_swap(v.begin()+largest,v.begin()+i);
		maxHeapify(v, largest,n);
	}
}

void createMaxHeap(std::vector<int> &v,int n){
	for(int i=n/2-1;i>=0;i--){
		maxHeapify(v,i,n);
	}
}

void addElement(std::vector<int> &v,int *n){
	int vi;
	cout<<"Enter element to be added :";
	cin>>vi;
	v.push_back(vi);
	*n++;

}

void heapSortIncreasing(std::vector<int> &v,int n){
	int size=n;
	createMaxHeap(v,n);
	while(size!=0){
	iter_swap(v.begin(),v.begin()+size-1);
	size--;
	maxHeapify(v,0,size);
	}
}

void heapSortDecreasing(std::vector<int> &v,int n){

}

void deleteElement(std::vector<int> &v,int *n){
	int d;
	if(n>0){
	cout<<"Enter position of element to be deleted :";
	cin>>d;
	v.erase(v.begin()+d);
	*n--;
	}
	else{
		cout<<"There is no element to delete\n";
	}
}
void printElements(std::vector<int> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}
void clearElements(std::vector<int> &v, int *n){
	v.clear();
	*n=0;
}


