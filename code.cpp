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
int editDistance(string s1,string s2,int m,int n)
{
	int dp[m+1][n+1];
	dp[0][0]=0;
	for(int i=1;i<=m;i++) dp[i][0]=i;
	for(int i=1;i<=n;i++) dp[0][i]=i;

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	return dp[m][n];
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
	string s1,s2;
	cin>>s1>>s2;
	int m=s1.length();
	int n=s2.length();
	int ans=editDistance(s1,s2,m,n);
	cout<<ans<<"\n";	
}
