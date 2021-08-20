#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int trailingZeroesFact(int n)
{
	int i=1;int ans=0;
	while(i*5<=n)
	{
		i=i*5;
		ans=ans+n/i;
	}
	return ans;
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
	
	cout<<trailingZeroesFact(n)<<"\n";
}