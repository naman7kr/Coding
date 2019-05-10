#include <bits/stdc++.h>
using namespace std;

typedef struct Node { 
	int data;
	struct Node *next; 
}Node;
void printLinearList(Node * node){
	while(node!=NULL){
		cout<<node->data<<" ";
		node=node->next;
	}
	cout<<"\n";
}
Node* insertEnd(Node* node){
	int info;
	cout<<"Enter data:";
	cin>>info;
	Node *st,*new_node;
	new_node=(Node*)malloc(sizeof(Node *));
	new_node->data=info;
	new_node->next=NULL;
	st=node;
	if(node==NULL){
		node=new_node;
		return node;
	}
	while(st->next!=NULL){
		st=st->next;
	}
	st->next=new_node;
	return node;
}
Node* insertBeg(Node* node){
	int info;
	Node* new_node=(Node*)malloc(sizeof(Node*));
	cout<<"Enter Data:";
	cin>>info;
	new_node->data=info;
	new_node->next=NULL;

	if(node==NULL){
		node=new_node;
		return node;
	}
	new_node->next=node;
	node=new_node;
	return node;
}
Node* insertAfter(Node* node){
	int info,prev;
	Node* st=node;
	Node* new_node=(Node*)malloc(sizeof(Node*));
	cout<<"Enter the data to be inserted:";
	cin>>info;
	new_node->data=info;
	new_node->next=NULL;
	if(node==NULL){
		node=new_node;
		return node;
	}
	cout<<"Enter the data of node after which data needs to be inserted:";
	cin>>prev;
	while(st!=NULL&&st->data!=prev){
		st=st->next;
	}
	if(st==NULL){
		cout<<"No node found corresponding to above data. Try again\n";
		return node;
	}
	Node *temp=st->next;
	st->next=new_node;
	new_node->next=temp;
	return node;
}
Node* insertBefore(Node* node){
	int info,prev;
	Node* st=node,*bef;
	Node* new_node=(Node*)malloc(sizeof(Node*));
	cout<<"Enter the data to be inserted:";
	cin>>info;
	new_node->data=info;
	new_node->next=NULL;
	if(node==NULL){
		node=new_node;
		return node;
	}
	cout<<"Enter the data of node before which data needs to be inserted:";
	cin>>prev;
	while(st!=NULL&&st->data!=prev){
		bef=st;
		st=st->next;
	}
	if(st==NULL){
		cout<<"No node found corresponding to above data. Try again\n";
		return node;
	}
	bef->next=new_node;
	new_node->next=st;
	return node;
}
Node* deleteNode(Node* node){
	if(node==NULL){
		cout<<"No node to delete\n";
		return node;
	}
	int info;
	Node* st=node,*prev=NULL;
	cout<<"Enter the data to be deleted:";
	cin>>info;
	while(st!=NULL&&st->data!=info){
		prev=st;
		st=st->next;
	}
	if(st==NULL){
		cout<<"Above data not found in the list\n";
		return node;
	}
	if(prev==NULL){
		node=st->next;
	}else 
	prev->next=st->next;
	free(st);
	return node;

}
void searchList(Node * node){
	int s;
	cout<<"Enter data to search in LinkedList:";
	cin>>s;
	if(node==NULL){
		cout<<"Data not found in the list\n";
		return ;
	}
	int i=1;
	while(node!=NULL){
		if(node->data==s){
			cout<<"Data found at "<<i<<"\n";
			return;
		}
		i++;
		node=node->next;
	}
	cout<<"Data not found in the list\n";
	return ;
}

main(){
	Node *root=NULL;
	while(1){
		int c;
		cout<<"Enter Case:";
		cin>>c;
		switch(c){
			case -1:
				return 0;
			case 0:
				printLinearList(root);
				break;
			case 1:
				root=insertEnd(root);
				printLinearList(root);
				break;
			case 2:
				root=insertBeg(root);
				printLinearList(root);
				break;
			case 3:
				root=insertAfter(root);
				printLinearList(root);
				break;
			case 4:
				root=insertBefore(root);
				printLinearList(root);
				break;
			case 5:
				root=deleteNode(root);
				printLinearList(root);
				break;
			case 6:
				searchList(root);
				break;
			default:
				cout<<"Wrong input\n";
				break;
		}
	}
	return 0;
}