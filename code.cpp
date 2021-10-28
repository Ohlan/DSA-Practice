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
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(s1[m-1]==s2[n-1])
		return editDistance(s1,s2,m-1,n-1);
	else
		return 1+min(editDistance(s1,s2,m-1,n-1),
					 min(editDistance(s1,s2,m,n-1),
					 editDistance(s1,s2,m-1,n)));
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
