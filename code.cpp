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
	int dp[n+1][m+1];
	for(int i=0;i<=m;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++) dp[i][0]=0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(coins[j-1]<=i)
			{
				dp[i][j]+=dp[i-coins[j-1]][j];
			}
		}
	return dp[n][m];
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
