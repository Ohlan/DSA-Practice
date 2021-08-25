#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
typedef struct node
{
	int data;
	node* next;
	node* rm;
	node(int data=0)
	{
		this->data=data;
		next=NULL;
		rm=NULL;
	}
}node;
void solve();
void printrmlist(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		if(head->rm)
			cout<<head->rm->data;
		cout<<"\n";
		head=head->next;
	}
	cout<<"\n";
}

node* clonelist(node* head)
{
	node* h=head;
	while(h)
	{
		node* temp=h->next;
		node* nw=new node(h->data);
		h->next=nw;
		h->next->next=temp;
		h=temp;
	}
	h=head;
	while(h)
	{
		h->next->rm=h->rm?h->rm->next:NULL;
		h=h->next->next;
	}
	h=head;
	node* clone=h->next;
	while(h->next->next)
	{
		node* temp=h->next;
		h->next=h->next->next;
		temp->next=temp->next->next;
		h=h->next;
	}
	h->next=NULL;
	return clone;
}
// node* mergesortedlist(node* h1,node* h2)
// {
// 	node* head;
// 	if(!h1)
// 		return h2;
// 	if(!h2)
// 		return h1;
// 	if((h1->data)>(h2->data))
// 	{
// 		head=h2;
// 		h2=h2->next;
// 	}
// 	else
// 	{
// 		head=h1;
// 		h1=h1->next;
// 	}
// 	node* temp=head;
// 	while(h1!=NULL&&h2!=NULL)
// 	{
// 		if((h1->data)>(h2->data))
// 		{
// 			temp->next=h2;
// 			temp=h2;
// 			h2=h2->next;
// 		}
// 		else
// 		{
// 			temp->next=h1;
// 			temp=h1;
// 			h1->next;			
// 		}
// 	}

// 	return head;
// }

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;
	cin>>t;
	while(t--)
		solve();
	
	return 0;
}
void solve()
{
	node* h1=new node(1);
	node* h2=new node(2);
	node* h3=new node(3);
	node* h4=new node(4);
	node* h5=new node(5);
	h1->next=h2;
	h2->next=h3;
	h3->next=h4;
	h4->next=h5;
	h1->rm=h3;
	h2->rm=h1;
	h3->rm=h5;
	h4->rm=h4;
	h5->rm=h1;
	printrmlist(h1);
	node* head=clonelist(h1);
	printrmlist(head);
	printrmlist(h1);
}