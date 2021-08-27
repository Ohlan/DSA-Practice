#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
typedef struct node {
    char data;
    struct node *left, *right;
}node;
 
node* newNode(char item)
{
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void solve();
void getInorder(node* root, char InT[],int &i)
{	
	if(!root)
	{
		InT[i++]='$';
		return;
	}
	getInorder(root->left,InT,i);
	InT[i++]=root->data;
	getInorder(root->right,InT,i);
}
void getPreorder(node* root, char InT[],int &i)
{	
	if(!root)
	{
		InT[i++]='$';
		return;
	}
	InT[i++]=root->data;
	getPreorder(root->left,InT,i);
	
	getPreorder(root->right,InT,i);
}
bool isSubtree(node* root,node* sub)
{
	if(!sub)
		return true;
	if(!root)
		return false;
	char InT[100],InS[100];
	int i=0,j=0;
	getInorder(root,InT,i);
	getInorder(sub,InS,j);
	InT[i]='\0',InS[j]='\0';
	char PreT[100],PreS[100];
	getPreorder(root,PreT,i);
	i=0,j=0;
	getPreorder(sub,PreS,j);
	if(strstr(InT,InS)==NULL)
		return false;

	return (strstr(PreT,PreS)!=NULL);
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
	node* T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    node* S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
 
    if (isSubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";

}