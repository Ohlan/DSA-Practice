#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MIN -1000000
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
int maximumIndex(int a[],int n)
{
	int s[n];
	s[0]=a[0];
	for(int i=1;i<n;i++)
	{
		s[i]=min(a[i],s[i-1]);
	}
	int l[n];
	l[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		l[i]=max(a[i],l[i+1]);
	}
	int i=0,j=0,ans=0;
	while(i<n&&j<n)
	{
		if(s[i]<=l[j])
		{
			ans=max(ans,j-i);
			j++;
		}
		else
		{
			i++;
		}
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
	int a[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	cout<<maximumIndex(a,n)<<"\n";

}