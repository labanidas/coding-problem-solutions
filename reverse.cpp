#include<bits/stdc++.h>
using namespace std;

class node{
	
	public:
		
		int data;
	node* next;
		node(int x){
			data=x;
			next=NULL;
		}
		
		void display(node* head){
			node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
		node* reverse(node* head){
			
			node* temp=head, *prev=NULL, *nextnode=head;
			
			while(nextnode!=NULL){
				
//				temp=temp->next;
				nextnode=temp->next;
				temp->next=prev;
//				temp->next=prev;
				prev=temp;
				temp=nextnode;
			}
			head=prev;
			
			return head;
		}
};

int main(){
	
	node* head;
	node* p = new node(0);
	head=p;
	
	
	for(int i=1;i<11;i++){
		p->next=new node(i);
		p=p->next;
	}
	head->display(head);
	
	head->display(head->reverse(head));	
	
}
