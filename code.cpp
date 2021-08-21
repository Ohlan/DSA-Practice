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
	node(int data=0)
	{
		this->data=data;
		next=NULL;
	}
}node;
void solve();
void printlist(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}
node* scanlist(int n)
{
	if(n<=0)
		return NULL;
	node* head=new node();
	cin>>head->data;
	head->next=NULL;
	node* prev=head;
	n--;
	while(n--)
	{
		node* temp=new node();
		cin>>temp->data;
		temp->next=NULL;
		prev->next=temp;
		prev=prev->next;
	}
	return head;
}
int looplength(node* head)
{
	node* slow=head;
	node* fast=head;
	int count=0,res=0;
	while(slow&&fast&&(fast->next))
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
			count++;
		if(count==1)
			res++;
		if(count==2)
			break;
	}
	return res;
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
	h5->next=h3;
	cout<<looplength(h1)<<" ";
	
}