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

void inorderIterative(node* root)
{
    stack<node*> rec;
    while(!rec.empty()||root)
    {
        if(root)
        {
            rec.push(root);
            root=root->left;
        }
        else
        {
            root=rec.top();
            rec.pop();
            cout<<root->data<<" ";
            root=root->right;
        }

    }    
    
}
void preorderIterative(node* root)
{
    stack<node*> rec;
    while(!rec.empty()||root)
    {
        if(root)
        {
            cout<<root->data<<" ";
            rec.push(root);
            root=root->left;
        }
        else
        {
            root=rec.top();
            rec.pop();            
            root=root->right;
        }

    }    
    
}

void postorderIterative(node* root)
{
    if(root==NULL)
        return;
    stack<node*> rec;
    stack<int> output;
    rec.push(root);
    while(!rec.empty())
    {
        node*temp=rec.top();
        rec.pop();
        output.push(temp->data);
        if(temp->left)
            rec.push(temp->left);
        if(temp->right)
            rec.push(temp->right);
        
    }    
    while(!output.empty())
    {
        cout<<output.top()<<" ";
        output.pop();
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
    root->left->left = new node(2);
    root->left->left->right = new node(1);
    root->left->right = new node(5);
    root->left->right->left = new node(4); 
    
    postorderIterative(root);
    
}