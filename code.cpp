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
	node* prev;
	node(int data=0)
	{
		this->data=data;
		next=NULL;
		prev=NULL;
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
	node* prev=head;
	n--;
	while(n--)
	{
		node* temp=new node();
		cin>>temp->data;
		temp->prev=prev;
		prev->next=temp;
		prev=prev->next;
	}
	prev->next=NULL;
	return head;
}

void sortKsorted(node **head,int k)
{
 	if((*head)==NULL||((*head)->next)==NULL)
 		return;
 	for(node* i=((*head)->next);i!=NULL;i=i->next)
 	{
 		node* j=i;
 		while(j->prev != NULL && j->data < j->prev->data) {
              // swap j and j.prev node
            node* temp = j->prev->prev;
            node* temp2 = j->prev;
            node* temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp;
            j->next = temp2;
            if(temp != NULL)
                temp->next = j;
            if(temp3 != NULL)
                temp3->prev = temp2;
        }
          // if j is now the new head
       // then reset head
        if(j->prev == NULL)
            (*head) = j;
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

	node* h=scanlist(n);
	printlist(h);
	sortKsorted(&h,2);
	printlist(h);	
}