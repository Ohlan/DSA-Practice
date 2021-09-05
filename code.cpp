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
void removeDuplicate(node* head)
{
	if(!head)
		return;
	node* curr=head->next;
	node* prev=head;
	
	while(curr)
	{	
		if(curr->data==prev->data)
		{
			prev->next=curr->next;
			curr=curr->next;
		}
		else
		{
			prev=curr;
			curr=curr->next;
		}
	}
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

	removeDuplicate(head);
	printlist(head);
	cout<<"\n";
}