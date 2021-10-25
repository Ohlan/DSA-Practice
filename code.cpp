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

int maxCuts(int n,int a, int b,int c)
{
	if(n<0)
		return -1;
	if(n==0)
		return 0;

	int res= max(maxCuts(n-a,a,b,c),max(maxCuts(n-b,a,b,c),maxCuts(n-c,a,b,c)));
	if(res!=-1)
		return res+1;
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
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	
	cout<<maxCuts(n,a,b,c)<<"\n";
}
