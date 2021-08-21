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
void swapKnodes(node **head,int n,int k)
{
	if(k>n||n<=1)
		return ;
	node* p1=(*head),*p2=(*head);
	node* prev1=NULL,*prev2=NULL;
	int n2=n-k;k--;
	while(n2--)
	{
		prev2=p2;
		p2=p2->next;
	}

	while(k--)
	{
		prev1=p1;
		p1=p1->next;
	}
	if(prev1)
	{
		prev1->next=p2;
		prev2->next=p1;
		node* temp=p1->next;
		p1->next=p2->next;
		p2->next=temp;
	}
	else
	{
		prev2->next=p1;
		node* temp=p1->next;
		p1->next=p2->next;
		p2->next=temp;
		(*head)=p2;
	}

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
	node* h1;
	node* h2;
	int n, m;
	cin>>n>>m;
	h1=scanlist(n);
	h2=scanlist(m);
	swapKnodes(&h2,m,1);
	// node* merged=mergesortedlist(h1,h2);
	printlist(h1);
	printlist(h2);
	// printlist(merged);

}