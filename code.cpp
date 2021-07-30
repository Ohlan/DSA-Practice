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
	
	ll n,count=0;
	cin>>n;
	ll a[n];
	for (auto &x: a) {
      cin >> x;
    }	
	ll min=20000000000,minp=20000000000;
	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]<minp&&a[i]!=min)
		{
			minp=a[i];
		}
	}
	if(minp>2*min)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]>=minp)
				count++;
		}
		if(count!=0)
			cout<<count<<"\n";
		else
			cout<<n<<"\n";
	}
	else
    	cout<<n<<"\n";
}