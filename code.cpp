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
node* reverseInGroup2(node* head,int k)
{
	if(!head)
		return NULL;
	node* curr=head;
	node* prev=NULL;

	stack<node*>s;
	while(curr)
	{	
		
		int i=1;
		while(curr&&i<=k)
		{
			s.push(curr);
			curr=curr->next;		
			i++;
		}
		
		while(!s.empty())
		{
			if(prev==NULL)
			{
				prev=s.top();
				head=prev;
				s.pop();
			}
			else
			{
				prev->next=s.top();
				prev=prev->next;
				s.pop();
			}
		}
		
	}
	prev->next=NULL;
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
	int n,k;
	cin>>n>>k;
	node* head=scanlist(n);

	head=reverseInGroup2(head,k);
	printlist(head);
	cout<<"\n";
	head=reverseInGroup2(head,k);
	printlist(head);
	cout<<"\n";
}