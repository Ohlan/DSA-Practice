#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MIN -1000000
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
int kadane(int a[],int n)
{
	int res=a[0];
	int maxend=a[0];
	for(int i=1;i<n;i++)
	{
		maxend=max(maxend+a[i],a[i]);
		res=max(res,maxend);
	}
	return res;
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

	cout<<kadane(a,n)<<"\n";

}