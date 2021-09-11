#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long mi=a[n-1];
    for(int i=0;i<=n-m;i++)
    {
        mi=min(mi,a[i+m-1]-a[i]);
    }
    return mi;
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

	vector<ll> a(n);
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<findMinDiff(a,n,5);
    cout<<"\n";
}