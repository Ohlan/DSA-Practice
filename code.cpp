#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
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
	int n;
	cin>>n;
	vi v(n);
	for(auto &x:v)
		cin>>x;
	int prev=0,curr=1;
	ll ans=0;
	for(;curr<n;curr++,prev++)
	{
		if(v[curr]<v[prev])
		{
			ans=ans+v[prev]-v[curr];
			v[curr]=v[prev];
		}
	}
	cout<<ans<<"\n";
}