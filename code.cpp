#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int* productPuzzle(int a[], int n )
{
    int* prod=new int[n];
    int m=1;
    for(int i=0;i<n;i++)
    {
    	prod[i]=m;
    	m*=a[i];
    }
    m=1;
    for(int i=n-1;i>=0;i--)
    {
    	prod[i]*=m;
    	m*=a[i];
    }
    return prod;
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
	int n;	
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int* b=productPuzzle(a,n);
    for(int i=0;i<n;i++)
    	cout<<b[i]<<" ";
}