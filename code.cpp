#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
ll findSubarray(ll a[], int n ) {
        map<ll,ll> mp;
    ll sum=0,c=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==0)
            c++;
        if(mp.find(sum)!=mp.end())
            c+=mp[sum];
        
        mp[sum]++;
    }
    return c;
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
	ll n;	
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<findSubarray(a,n)<<"\n";
}