#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();

int peak(vi a,int l,int r)
{
	int n=r+1;
	while(l<=r)
	{
		int mid =(l+r)/2;

		if((mid==0||a[mid]>a[mid-1])&&(mid==n-1||a[mid]>a[mid+1]))
			return a[mid];
		else if(a[mid]<a[mid-1])
			r=mid-1;
		else
			l=mid+1;
	}
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
	cout<<peak(a,0,n-1)<<"\n";
}