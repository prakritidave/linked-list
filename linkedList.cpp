// linkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node{
	int info;
	Node *next;
};

class linkedlist{
	Node *head;

public:
	linkedlist(){
		head=NULL;
	}

	//reverses linked list in size of k
	Node* reverseInSizeOfK(Node *head, int k){

	 if(head == NULL || head->next == NULL)return head;

	   Node *current=head;	
	   Node *prev=NULL;
	   Node *next=NULL;
	   int count=0;

	   while(current!=NULL && count<k){
		   next=current->next;
		   current->next=prev;
		   prev=current;
		   current=next;
		   count++;
	   }

	   head->next=reverseInSizeOfK(next,k);

	   return prev;
	};

	void reversek(int k){

		head=reverseInSizeOfK(head, k);
	}
	
	
       //insert element in linked list
	void insert(int n){
	
		Node *node=new Node();
		node->info=n;
		node->next=NULL;

		if (head==NULL)			
			head=node;	

		else{
			Node *p=head;
			while(p->next!=NULL)
				p=p->next;

			p->next=node;			
		}
	}
               //delete a node from linked list
		void deleteNode(int n){

			Node *p=head->next;
			Node *q=head;

			if(head==NULL)

		      cout<<"List is empty, no element to delete";
			
			else if(head->info==n) 
			{
				Node *r = head;
				head=head->next;
				delete r;

			}
			else
			{
				
				while(p!=NULL)
				{
					if(p->info == n)
					{
						q->next=p->next;						
						break;
					}   
					else
					{
						q=p;
						p=p->next;
					}
				}
		    if(p==NULL)
			{
				cout<<"\nelement not found";
				
			}
			else
			{
				delete p;
			}

			}
			
		}
             //reverse a linked list
		void reversell()
		{
			Node *p=head;
			Node *q=p->next;
			Node *r=q->next;

			while(q!=NULL)
			{
				q->next=p;
				p=q;
				q=r;

				if(r == NULL)
					break;
				else
					r=r->next;
			}
			
			head->next=NULL;
			head=p;
		}
              //display linked list
		void displayll()
		{
			Node *p=head;

			while(p!=NULL){
				cout<<p->info<<" ";
				p=p->next;
			}

		}
             //recursively reverse a linked list
		void recrevll(){
			head = recrev(head);
		}
               //recursive reverse linked list and returns the new head
		Node* recrev(Node* headptr){

			Node *p=headptr;
			Node *q=p->next;

			head->next=NULL;

			if(q->next!=NULL)
			{
				headptr=recrev(q);
				q->next=p;
			}
			else
			{
				q->next=p;
				headptr=q;
			}

			
			return headptr;
		}
	//prints nth node from the end of a linked list
		void nthToLast(int n){
			int x;
			
			if(n==0)
				x=1;
			else
				x=n-1;

			Node *p=head;
			Node *q=p;

			while(x!=0 && q!=NULL)
			{
				q=q->next;
				x--;
			}

			if(q==NULL)
			{
				cout<<"\nposition out of bounds";
				return;
			}
				

			if(q->next == NULL)
				cout<<p->info;
			else
			{
				while(q->next!=NULL)
				{
					p=p->next;
					q=q->next;
				}
				cout<<p->info;
			}
				
		}
             //checks if there is a loop in the linked list
		void findLoop(){
		
			Node *slow=head;
			Node *fast=head->next;
			while(slow!=fast && fast!=NULL){
				slow=slow->next;
				fast=fast->next->next;
			}

			if(fast==NULL)
			cout<<"\n no loop";						
			else			
			cout<<"\nloop found";
			
				return;
		}

             //remove duplicates from a linked list
		void remDuplicates(){
		
			if(head == NULL)return;

			Node *prev=head;
			Node *curr=head->next;

			while(curr!=NULL){

			  Node *runner=head;
			 while(runner!=curr){

				if(runner->info == curr->info){
					Node *tmp=curr->next;
					prev->next=tmp;
					curr->next=NULL;
					delete curr;
					curr=tmp;
					break;
				}
				runner=runner->next;
			 }
			 if(runner == curr){
				 prev=curr;
				 curr=curr->next;
			 }
        }
	}

	//swaps the nth element from the first and last
		void swapNthFromFirstAndLast(int n)
		{
			int x,temp;
			Node *swap1,*swap2,*p,*q;
			
			if(n==0)
				x=1;
			else
				x=n-1;

			p=head;
			q=p;

			while(x!=0 && q!=NULL)
			{
				q=q->next;
				x--;
			}

			if(q==NULL)
			{
				cout<<"\nposition out of bounds";
				return;
			}
				

			if(q->next == NULL)
			{				
				temp = p->info;
				p->info = q->info;
				q->info = temp;				
			}				
			else
			{
				swap1=q;
				while(q->next!=NULL)
				{
					p=p->next;
					q=q->next;
				}

				swap2=p;

				temp=swap1->info;
				swap1->info=swap2->info;
				swap2->info=temp;
				
			}

		}
};



int _tmain(int argc, _TCHAR* argv[])
{
	int num,n,x,d,last,pos,k;
	
	linkedlist ll;
	cout<<"\n enter number of elements to insert";
	cin>>n;

	num=n;

	while(num!=0){
		cout<<"\nenter number to be inserted";
		cin>>x;
		ll.insert(x);
		ll.displayll();
		num--;
	}
	

	/*if(n!=0)
	{
	  cout<<"\n enter number to be deleted";
	  cin>>d;
	  ll.deleteNode(d);
	  ll.displayll();
	  ll.recrevll();

	  cout<<"\n";

	  ll.displayll();

	 cout<<"\nenter position of element to be viewed from last";
	 cin>>last;

	 ll.nthToLast(last);

	 cout<<"\nenter position of element to be swapped";
	 cin>>pos;

	 ll.swapNthFromFirstAndLast(pos);
	 ll.remDuplicates();
	 ll.displayll();
	}*/	

	cout<<"\n to reverse in sizes of k, enter k";
	cin>>k;
	ll.reversek(k);

	ll.displayll();

   return 0;
}

