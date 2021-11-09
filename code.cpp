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

/*
 * Complete the 'numberOfWays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY roads as parameter.
 */


int renameFile(string newName, string oldName,int n,int m)
{
    int dp[n+1][m+1];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        dp[i][0]=0;
    for(int i=1;i<=m;i++)
        dp[0][i]=1;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(newName[i-1]!=oldName[j-1])
                dp[i][j]=dp[i][j-1];
            else
                dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
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
    string newName,oldName;
    cin>>newName>>oldName;
    cout<<renameFile(newName,oldName,n,m)<<"\n";
}

