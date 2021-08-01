#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();
int binomialCoeff(int n, int k)
{
    int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
 
void print(vi &a)
{
	for(auto x:a)
		cout<<x<<" ";
	cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// int t;
	// cin>>t;
	// while(t--)
		// solve();
	solve();
	return 0;
}
void solve()
{
	ll n,q;
	cin>>n>>q;
	while(q--)
	{
		ll w,ans=0;
		cin>>w;
		ll k=1; 
		if(w>3)
		{
			k=w/3;
			if(w%3!=0)
				k++;
		}
		k=3*k;
		while(k<=n*3)
		{
			ans=((ans%1000000007)+(binomialCoeff(k,w))%1000000007)%1000000007;
			k=k+3;
		}
		cout<<ans<<"\n";
	}	
}