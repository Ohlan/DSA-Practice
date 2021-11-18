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
void inOrder(node* root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
pair<int,int> minMax(node* root)
{
    pair<int,int> p;
    node* t1=root,*t2=root;
    int x=INT_MIN,y=INT_MAX;
    while(t1||t2)
    {
        if(t1)
            if(t1->data>x)
            {
                x=t1->data;
                t1=t1->right;
            }
        if(t2)
            if(t2->data<y)
            {
                y=t2->data;
                t2=t2->left;
            }
    }
    return p=make_pair(x,y);
}

node* searchInBST(node* root,int key)
{
    if(root==NULL||root->data==key)
        return root;
    if(root->data>key)
        return searchInBST(root->left,key);
    else
        return searchInBST(root->right,key);
}


node* predForDeletion(node* root)
{
    if(root==NULL||root->left==NULL)
        return NULL;
    root=root->left;
    while(root->right)
        root=root->right;
    return root;
}
node* findParent(node* root,int key,node* par)
{
    if(root->data==key)
        return par;
    par=root;
    if(root->data>key)
        return findParent(root->left,key,par);
    else
        return findParent(root->right,key,par);
}
node* deleteInBST(node* root,int key)
{
    node* temp= searchInBST(root,key);
    if(temp==NULL)
        return root;
    node* par = findParent(root,key,NULL);
    if(temp->left==NULL&&temp->right==NULL)
    {
        if(par==NULL)
            return NULL;
        if(par->left==temp)
            par->left=NULL;
        else
            par->right=NULL;
        return root;
    }
    else if(temp->left==NULL||temp->right==NULL)
    {
        node* grand= (temp->left==NULL)?temp->right:temp->left;
        if(par==NULL)
        {
            return grand;
        }
        else
        {
            if(par->left==temp)
                par->left=grand;
            else
                par->right=grand;
            return root;
        }
    }
    else
    {
        node* pred= predForDeletion(temp);
        
        int x=pred->data;
        root=deleteInBST(root,pred->data);
        temp->data= x;
        return root;
    }

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
    root->left->left = new node(1);
    root->left->left->right = new node(2);
    root->left->right = new node(5);
    root->left->right->left = new node(4); 
    
    inOrder(root);
    root = deleteInBST(root,6);
    root = deleteInBST(root,5);
    root = deleteInBST(root,7);
    root = deleteInBST(root,7);
    cout<<"\n";
    inOrder(root);
    
}



/*

TreeNode* inorderSucc(TreeNode* root)
    {
        TreeNode* curr = root;
        while(curr!=NULL && curr->left!=NULL)
        {
            curr = curr->left;
        }
        return curr;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)
        {
            return NULL;
        }
        
        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(root->left == NULL)
            {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            else if(root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
                TreeNode* temp = inorderSucc(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
        }
        
        return root;
    }

*/