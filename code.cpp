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
int height(node* root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;

}
void verticalWidth(node* root,int& min,int& max,int count=0)
{
	if(!root)
		return;
	if(count<min)
		min=count;
	if(count>max)
		max=count;
	verticalWidth(root->left,min,max,count-1);
	verticalWidth(root->right,min,max,count+1);
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
    int min=1,max=-1;
    verticalWidth(root,min,max);
    cout<<max-min+1<<"\n";
}