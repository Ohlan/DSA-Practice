#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve();
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
	
	ll n;
	cin>>n;
	ll a[n],j=0;
	for(auto i:a)
	{
		cin>>a[j++];
	}	
	ll max=0;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]*a[i+1]>max)
			max=a[i]*a[i+1];
	}
    cout<<max<<"\n";
}