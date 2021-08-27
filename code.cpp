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
bool isbalanced(node* root)
{
	if(!root)
		return true;
	int lh=height(root->left);
	int rh=height(root->right);
	if(abs(lh-rh)<=1&&(isbalanced(root->left))&&(isbalanced(root->right)))
		return true;
	else
		return false;
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
    cout<<isbalanced(root);
}