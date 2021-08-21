#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
void sortedsearch(int** a,int n,int x)
{
	int i=0,j=n-1;
	while(i<n&&j>=0)
	{
		if(a[i][j]==x)
		{
			cout<<"element present at:"<<i<<" "<<j<<"\n";
			return;
		}
		if(a[i][j]<x)
			i++;
		else
			j--;
	}
	cout<<"element not found\n";
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
	int* a[n];
	int x=16;
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			a[i][j]=j+i*n+1;
		}
	}

	sortedsearch(a,n,x);

	

}