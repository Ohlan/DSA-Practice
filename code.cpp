#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
void rearrange(int a[],int n)
{
	int max=n;
	for(int i=0;i<n;i++)
	{
		a[i]+=(a[a[i]]%max)*max;
	}
	for(int i=0;i<n;i++)
	{
		a[i]/=max;
	}
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

	rearrange(a,n);

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

}