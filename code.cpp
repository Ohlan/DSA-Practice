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
	node* left;
	node* right;
	node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
}node;
void solve();
void spiral(node* root)
{
	if(!root)
		return;

	queue<node*> q;
	q.push(root);
	q.push(NULL);
	int flag=0;
	while(!q.empty())
	{
		node* temp=q.front();
		if(temp)
		{
			while(q.front()!=NULL)
			{
				cout<<temp->data<<" ";
				if(flag==0)
				{
					if(temp->right)
					{
						q.push(temp->right);
					}
					if(temp->left)
					{
						q.push(temp->left);
					}
				}
				else
				{
					if(temp->left)
					{
						q.push(temp->left);
					}
					if(temp->right)
					{
						q.push(temp->right);
					}
				}
				
				q.pop();
				temp=q.front();
			}
			cout<<"\n";
			q.push(NULL);
		}
		if(flag==0)
			flag=1;
		else
			flag=0;
		q.pop();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	// int t;
	// cin>>t;
	// while(t--)
		solve();
	
	return 0;
}

void solve()
{
	node *root = new node(6);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->left->right = new node(1);
    root->left->right = new node(5);
    root->left->right->left = new node(4); 
    spiral(root);
}