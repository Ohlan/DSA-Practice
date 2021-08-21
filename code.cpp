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
void reversell(node** head)
{
	if(!(*head))
		return;
	node *prev=NULL;
	node *curr=(*head);
	node *temp;
	while(curr)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	(*head)=prev;
}
bool isPalindrome(node* head)
{
	node* mid=head;
	node* h2=head;
	while(mid&&h2&&(h2->next))
	{
		mid=mid->next;
		h2=h2->next->next;
	}
	h2=mid->next;
	reversell(&h2);
	while(h2)
	{
		if(h2->data!=head->data)
			return false;
		h2=h2->next;
		head=head->next;
	}
	return true;
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
	node* head;
	int n;
	cin>>n;
	head=scanlist(n);
	
	
	// node* merged=mergesortedlist(h1,h2);
	cout<<isPalindrome(head);
	// printlist(merged);
	
}