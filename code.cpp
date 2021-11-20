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
void storeInorderInArray(vector<node*> &array,node* root)
{
    if(root)
    {
        storeInorderInArray(array,root->left);
        array.push_back(root);
        storeInorderInArray(array,root->right);
    }
}
void printBST(node* root)
{
    if(root)
    {
        printBST(root->left);
        cout<<root->data<<" ";
        printBST(root->right);
    }
}
node* normalToBalancedBST(vector<node*> &array, int start,int end)
{
    if(start>end)
        return NULL;
    int mid = (start+end)/2;
    array[mid]->left = normalToBalancedBST(array, start, mid-1);
    array[mid]->right = normalToBalancedBST(array, mid+1, end);
    return array[mid];
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
    vector<node*> array;
    storeInorderInArray(array,root);
    int n=array.size();
    levelorder(root);
    cout<<"\n";   
    root = normalToBalancedBST(array,0,n-1);
    levelorder(root);
    
    
}

