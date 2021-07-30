#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve();
void rec(ll n)
{
	cout<<n<<" ";
	if(n==1)
		return;
	else
	{
		if(n%2==0)
			rec(n/2);
		else
			rec(3*n+1);
	}
}
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
	rec(n);
}