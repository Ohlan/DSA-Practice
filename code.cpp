#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
typedef struct node
{
    int key;
    int hd;
    struct node* left;
    struct node* right;
    node(int data)
    {
        this->key = data;
        left = right = NULL;
    }
}node;
void solveBT();
void findPreSuc(node* root, node*& pre, node*& suc, int key)
{
    if(root==NULL)
        return ;
    if(root->key==key)
    {
        if(root->left)
        {
            pre = root->left;
            while(pre->right)
                pre=pre->right;
            
        }
        if(root->right)
        {
            suc = root->right;
            while(suc->left)
                suc=suc->left;
        }
        
    }
    else if(key> root->key)
    {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
    else
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
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
    
    node* t1=NULL,*t2=NULL;
    findPreSuc(root,t1,t2,5);
    cout<<t1->key<<" ";
    cout<<t2->key<<" ";
    cout<<"\n";   
    
}

