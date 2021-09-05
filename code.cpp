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

node* addOne(node* head)
{
	if(!head)
		return NULL;
	node* last=NULL,*curr=head;
	while(curr->next)
	{
		if(curr->data!=9)
			last=curr;
		curr=curr->next;
	}
	if(curr->data!=9)
	{
		curr->data++;
		return head;
	}
	if(last==NULL)
	{
		node* t=new node(1);
		t->next=head;
		curr=head;
		while(curr)
		{
			curr->data=0;
			curr=curr->next;
		}
		return t;
	}
	
	(last->data)+=1;
	curr=last->next;
	while(curr)
	{
		curr->data=0;
		curr=curr->next;
	}
	return head;
	
}
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
	int n;
	cin>>n;
	node* head=scanlist(n);

	head=addOne(head);
	printlist(head);
}