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

int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,stack<int>> st;
        
        for(int i=0;i<2*e;i+=2)
        {
            st[A[i]].push(A[i+1]);
        }
        
        for(int i=0;i<2*e;i+=2)
        {
            if(st.find(B[i])==st.end())
            {
                return 0;
            }
            if(st[B[i]].top()!=B[i+1])
                return 0;
            st[B[i]].pop();
        }
        return 1;
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
    
    
    
}