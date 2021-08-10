#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();
int binarysearch(vi a,int l,int r,int e)
{
	if(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==e)
			return mid;
		else if(a[mid]>e)
			return binarysearch(a,l,mid-1,e);
		else
			return binarysearch(a,mid+1,r,e);
	}
	return -1;
}
int ternarysearch(vi a,int l,int r,int e)
{
	if(l<=r)
	{
		int mid1=l+(r-l)/3;
		int mid2=r-(r-l)/3;
		if(e==a[mid1])
			return mid1;
		else if(e==a[mid2])
			return mid2;
		else if(e<a[mid1])
			return ternarysearch(a,l,mid1-1,e);
		else if(e>a[mid2])
			return ternarysearch(a,mid2+1,r,e);
		else
			return ternarysearch(a,mid1+1,mid2-1,e);
	}
	return -1;
}
int iterative_bs(vi a,int l,int r,int e)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==e)
			return mid;
		else if(a[mid]<e)
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
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
	cout<<binarysearch(a,0,n-1,85)<<"\n";
	cout<<ternarysearch(a,0,n-1,85)<<"\n";
	cout<<iterative_bs(a,0,n-1,85)<<"\n";
}