#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solveBT();
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

void diogonalQueueIterative(node* root)
{
    if(root)
    {
        queue<node*> q;
        node* temp=root;
        q.push(temp);
        while(!q.empty())
        {
            
            int size=q.size();
            while(size--)
            {
                temp=q.front();
                q.pop();
                while(temp)
                {
                    cout<<temp->data<<" ";
                    if(temp->left)
                        q.push(temp->left);
                    temp=temp->right;
                }
            }
            cout<<"\n";

        }

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
    
    diogonalQueueIterative(root);
    
}