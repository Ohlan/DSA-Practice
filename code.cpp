#include<bits/stdc++.h>
using namespace std;
// #define mod 1000000007
#define INF INT_MAX
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
void solve();

ll noOfWays(int n,int m, vi &coins)
{
	if(n==0)
	{
		return 1;
	}
	if(m==0)
		return 0;
	int res=noOfWays(n,m-1,coins);
	if(coins[m-1]<=n)
		res=res+noOfWays(n-coins[m-1],m,coins);
	return res;
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
	int n,m;
	cin>>n>>m;
	vi coins(m);
	for(auto &x:coins)
	{
		cin>>x;
	}
	cout<<noOfWays(n,m,coins)<<"\n";
}
