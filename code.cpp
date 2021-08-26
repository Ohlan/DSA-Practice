#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
typedef struct node
{
	int data;
	int hd;
	struct node* left;
	struct node* right;
	node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
}node;
void solveBT();
void levelorder(node* root)
{
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(q.empty()==false)
	{
		node* temp=q.front();
		if(temp)
		{
			while(q.front()!=NULL)	
			{
				cout<<temp->data<<" ";
				if (temp->left != NULL) 
		            q.push(temp->left); 

		        if (temp->right != NULL) 
		            q.push(temp->right); 
				q.pop();
				temp=q.front();
			}
			cout<<"\n";
			q.push(NULL);
		}
		q.pop();
	}
}
void leftview(node* root)
{
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(q.empty()==false)
	{
		node* temp=q.front();
		if(temp)
		{
			cout<<temp->data<<"\n";
			while(q.front()!=NULL)	
			{
				if (temp->left != NULL) 
		            q.push(temp->left); 

		        if (temp->right != NULL) 
		            q.push(temp->right); 
				q.pop();
				temp=q.front();
			}
			q.push(NULL);
		}
		q.pop();
	}
}
void rightview(node* root)
{
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(q.empty()==false)
	{
		node* temp=q.front();
		if(temp)
		{
			node* t;
			while(q.front()!=NULL)	
			{
				if (temp->left != NULL) 
		            q.push(temp->left); 

		        if (temp->right != NULL) 
		            q.push(temp->right);
		        t=temp; 
				q.pop();
				temp=q.front();
			}
			cout<<t->data<<"\n";
			q.push(NULL);
		}
		q.pop();
	}
}
void topview(node* root)
{
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	int hd=0;
	root->hd=0;
	map<int,int> mp;
	while(q.empty()==false)
	{
		node* temp=q.front();
		hd=temp->hd;
		if(mp.count(hd)==0)
			mp[hd]=temp->data;
		if (temp->left != NULL) 
		{
			temp->left->hd=hd-1;
		    q.push(temp->left);
		} 
        if (temp->right != NULL) 
        {
        	temp->right->hd=hd+1;
        	q.push(temp->right);
        }
        q.pop();
	}
	for(auto x:mp)
		cout<<x.second<<" ";
}
void bottomview(node* root)
{
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	int hd=0;
	root->hd=0;
	map<int,int> mp;
	while(q.empty()==false)
	{
		node* temp=q.front();
		hd=temp->hd;
		mp[hd]=temp->data;
		if (temp->left != NULL) 
		{
			temp->left->hd=hd-1;
		    q.push(temp->left);
		} 
        if (temp->right != NULL) 
        {
        	temp->right->hd=hd+1;
        	q.push(temp->right);
        }
        q.pop();
	}
	for(auto x:mp)
		cout<<x.second<<" ";
}
int height(node* root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;

}
int diameter(node* root)
{
	if(root==NULL)
		return 0;
	return max(diameter(root->left),max(diameter(root->right),height(root->left)+height(root->right)+1));
}

void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	solveBT();
	return 0;
}
void solveBT()
{
	
	node *root = new node(6);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->left->right = new node(1);
    root->left->right = new node(5);
    root->left->right->left = new node(4); 
	
	cout<<height(root)<<"\n";
	cout<<diameter(root)<<"\n";
}
