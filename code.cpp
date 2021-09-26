#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
void solve();
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
	int ans1=0,ans2=a[0];
  	
  	for(int i=0;i<n;i++)
	{
		ans2|=a[i];
	}

  	for(int i=0;i<32;i++)
	{
	    int cnt=0;
	    for(int j=0;j<n;j++)
	    {
	       if(a[j]%2==0) cnt++;
	       a[j]/=2;
	    }
	    if(cnt!=n)
	    {
	      ans1 += (1<<i);
	    }
	}
	cout<<ans1<<" "<<ans2<<"\n";
}
