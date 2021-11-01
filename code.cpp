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
int lis(vi a,int n)
{
	if(n==0)
		return 0;
	vi lisEndingWithCurr(n);
	lisEndingWithCurr[0]=1;

	for(int i=1;i<n;i++)
	{
		int m=1;
		for(int j=0;j<i;j++)
		{
			int curr;
			if(a[j]<a[i])
			{
				curr=lisEndingWithCurr[j]+1;
				m=max(m,curr);
			}
		}
		lisEndingWithCurr[i]=m;
	}
	int m=1;
	for(int i=0;i<n;i++)
		m=max(m,lisEndingWithCurr[i]);
	return m;

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
	vi a(n);
	for(auto &x:a)
		cin>>x;
	
	cout<<lis(a,n)<<"\n";
}
