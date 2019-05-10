#include <bits/stdc++.h>
using namespace std;

typedef struct List
{
	int data;
	struct List *next;
}List;
List* createList(){
	int n;
	scanf("%d",&n);
	List *head=NULL;
	List *ptr=head;
	for(int i=1;i<=n;i++){
		List* new_node=(List*)malloc(sizeof(List));
		scanf("%d",&new_node->data);
		if(i==1){
			ptr=new_node;
			ptr->next=NULL;
			head=ptr;
		}else{
			ptr->next=new_node;
			ptr=ptr->next;
			ptr->next=NULL;
		}
	}

	//cout<<head->next->data<<"\n";
	return head;
}
List* mergeLists(List* a, List* b){
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	List *res=NULL;
	if(a->data<=b->data){
		res=a;
		res->next=mergeLists(a->next,b);
	}else{
		res=b;
		res->next=mergeLists(b->next,a);
	}
	return res;
}
void printList(List* node){
	if(!node)
		return;
	printf("%d ", node->data);
	printList(node->next);
}
main(){
	List *h1= NULL;
	h1=createList();
	List *h2=NULL;
	h2=createList();
	List *t1=NULL,*t2=NULL;
	List *h3=mergeLists(t1,t2);
	printList(h1);
	cout<<"\n";
	printList(h3);
	cout<<"\n";
}