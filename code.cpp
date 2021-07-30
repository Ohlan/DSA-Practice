#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve();
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// int t;
	// cin>>t;
	// while(t--)
	// 	solve();
	solve();
	return 0;
}
void solve()
{
	
	ll n;
	cin>>n;
	int sum=n*(n+1)/2;
	n--;
	int c=0;
	while(n--)
	{
		int t;
		cin>>t;
		c+=t;
	}
	cout<<sum-c<<"\n";
}