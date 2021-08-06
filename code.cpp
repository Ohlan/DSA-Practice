#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	// solveBT();
	return 0;
}
void solve()
{
	int n,p,k;
	cin>>n>>p>>k;
	n--;
	int rem=p%k;
	ll ans=0;
	if(rem==0)
		ans=p/k;
	else
	{
		int d1=n%k,temp=n/k+1;
		if(rem<=d1)
		{
			ans=ans+(rem*temp);
		}
		else
		{
			ans=ans+((d1+1)*(temp))+((rem-d1-1)*(temp-1));
		}
		ans+=p/k;
	}
	ans++;
	cout<<ans<<"\n";
}