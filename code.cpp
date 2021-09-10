#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

int floorsqrt(int n)
{
	if(n==1||n==0)
		return n;
	int start=0,end=n,ans;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(mid*mid==n)
			return mid;
		else if(mid*mid<n)
		{
			ans=mid;
			start=mid+1;
		}
		else
			end=mid-1;
	}
	return ans;
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
	cout<<floorsqrt(n)<<"\n";
}