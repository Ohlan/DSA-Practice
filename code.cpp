#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
ull binexp(ull base, ull pow, ull M = mod){
    ull res = 1;
    while(pow){
        if(pow & 1) res *= base;
        pow >>= 1, base *= base;
        if(M) base %= M, res %= M;
    }
    return res;
}
int subsum(vi a,int i,int sum)
{
	int n=a.size();
	if(i>=n)
	{
		return sum;
	}
	else
		return (subsum(a,i+1,sum)+subsum(a,i+1,(sum+a[i])%mod))%mod;
}
int N=1e5+10;
vi a(N);
vi sz(N);
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    a[0]=0,a[1]=1;
	sz[0]=1,sz[1]=1;
	for(int i=2;i<=N-10;i++)
	{
		a[i]=(a[i-1]+a[i-2])%mod;
		sz[i]=(sz[i-1]+sz[i-2])%(mod-1);
	}
	int t;
	cin>>t;
	while(t--)
		solve();
	// solveBT();
	return 0;
}
void solve()
{
	int n;
	cin>>n;
		
	ull sum=a[n];
	sum=(sum*binexp(2,sz[n]-1))%mod;
	cout<<sum<<"\n";

}