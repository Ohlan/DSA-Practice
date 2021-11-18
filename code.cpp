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
node* searchInBST(node* root,int key)
{
    if(root==NULL||root->data==key)
        return root;
    if(root->data>key)
        return searchInBST(root->left,key);
    else
        return searchInBST(root->right,key);
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
    
    node* ele= searchInBST(root,4);
    if(ele)
        cout<<ele->data<<": element found";
    else
        cout<<"element not found";
    
}