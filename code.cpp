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
typedef struct dllnode
{
	int data;
	struct dllnode* prev;
	struct dllnode* next;
	dllnode(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
}dllnode;
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
node* LCA(node* root,int k1,int k2)
{
	if(!root)
		return NULL;
	if(root->data==k1||root->data==k2)
		return root;

	node* leftlca=LCA(root->left,k1,k2);
	node* rightlca=LCA(root->right,k1,k2);
	if(leftlca!=NULL&&rightlca!=NULL)
		return root;
	return (leftlca!=NULL)?leftlca:rightlca;
}
void BT2Dll(node* root,dllnode** head)
{
	if(root==NULL)
	{
		return;
	}
	static dllnode* prev=NULL;
	BT2Dll(root->left,head);
	dllnode* temp=new dllnode(root->data);

	if(!prev)
	{
		temp->prev=NULL;
		prev=temp;
		(*head)=temp;
	}
	else
	{
		temp->prev=prev;
		prev->next=temp;
		prev=temp;
	}

	BT2Dll(root->right,head);
}
int height(node* root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;

}
void printlist(dllnode* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
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
	node* lca=LCA(root,1,7);
	cout<<lca->data<<"\n";
	lca=LCA(root,1,3);
	cout<<lca->data<<"\n";
	dllnode* head;
	BT2Dll(root,&head);
	printlist(head);
	
}
