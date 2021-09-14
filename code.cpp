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
void printcircularlist(node* head,int n)
{
	while(n--)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}
node* scancircularlist(int n)
{
	if(n<=0)
		return NULL;
	node* head=new node();
	cin>>head->data;
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
	prev->next=head;
	return head;
}

void splitList(node *head, node **head1_ref, node **head2_ref)
{
    if(head==NULL)
    {
    	(*head1_ref)=NULL;
    	(*head2_ref)=NULL;
    }
    if(head->next==NULL)
    {
    	(*head1_ref)=head;
    	(*head2_ref)=NULL;
    }
    (*head1_ref)=head;
    node *temp=head;
    int n=0;
    while(temp)
    {
    	if(temp==head&&n!=0)
    		break;
    	temp=temp->next;
    	n++;
    }
    int k=(n%2)?(n/2+1):(n/2),i=1;
    while(i<=n)
    {
    	if(i==k)
    	{
    		(*head2_ref)=temp->next;
    		temp->next=head;
    		temp=(*head2_ref);
    		i++;
    		continue;
    	}
    	if(i==n)
    	{
    		temp->next=(*head2_ref);
    	}
    	temp=temp->next;
    	i++;
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

	node* h1=scancircularlist(n);

	node* h2,*h3;
	printcircularlist(h1,n);
	splitList(h1,&h2,&h3);
	printcircularlist(h2,ceil(((float)n)/2));
	printcircularlist(h3,n/2);
	
}