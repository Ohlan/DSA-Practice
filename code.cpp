#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();

int count_repeating(vi a,int l,int r,int e)
{
	int first,last,high=r,low=l;
	int n=r-l+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid==0||(a[mid]==e&&a[mid-1]<e))
		{
			first=mid;
			break;
		}
		else if(a[mid]<e)
			l=mid+1;
		else
			r=mid-1;
	}	
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(mid==n-1||(a[mid]==e&&a[mid+1]>e))
		{
			last=mid;
			break;
		}
		else if(a[mid]<=e)
			low=mid+1;
		else
			high=mid-1;
		
	}
	return last-first+1;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	// solveBT();
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	vi a(n);
	for(auto &x:a)
		cin>>x;
	sort(a.begin(),a.end());
	cout<<count_repeating(a,0,n-1,3)<<"\n";
}