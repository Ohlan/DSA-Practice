#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define INF INT_MAX
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
void solve();
int memo[7][7];

int lcs(string a,string b,int n,int m)
{
	if(n==0||m==0)
		return 0;
	if(a[n-1]==b[m-1])
		return 1+lcs(a,b,n-1,m-1);
	else
	{
		return max(lcs(a,b,n,m-1),lcs(a,b,n-1,m));
	}
}
int lcsMemo(string a,string b,int n,int m)
{
	if(memo[n][m]!=-1)
		return memo[n][m];
	if(n==0||m==0)
		memo[n][m]= 0;
	else if(a[n-1]==b[m-1])
		memo[n][m]= 1+lcs(a,b,n-1,m-1);
	else
	{
		memo[n][m]= max(lcs(a,b,n,m-1),lcs(a,b,n-1,m));
	}
	return memo[n][m];
}
int lcsDP(string a,string b,int n,int m)
{
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
		dp[i][0]=0;
	for(int i=0;i<=m;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
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
	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++)
			memo[i][j]=-1;
	while(t--)
		solve();	
	return 0;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	string a,b;
	cin>>a>>b;
	cout<<lcsMemo(a,b,n,m)<<"\n";	
}
