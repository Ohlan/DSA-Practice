#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
typedef struct node
{
	int data;
	vector<node> components;
	node(){}
	node(int data)
	{
		this->data=data;
	}	
}node;
void solve();
void merge(int a1[], int a2[], int n, int m) {
	    int i=0,j=0;
	    while(i<n&&j<m)
	    {
	        if(a1[i]<=a2[j])
	        {
	            cout<<a1[i]<<" ";
	            i++;
	        }
	        else
	        {
	            cout<<a2[j]<<" ";
	            j++;
	        }
	        
	    }
	    while(i<n)
	    {
	        cout<<a1[i]<<" ";
	        i++;
	        
	    }
	    while(j<m)
	    {
	        cout<<a2[j]<<" ";
	        j++;
	    }
	    cout<<"\n";
	}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;
	cin>>t;
	while(t--)
		solve();
	
	return 0;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int j=0;j<m;j++)
		cin>>b[j];
	merge(a,b,n,m);


}