#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

int findLast(vector<int>&a,int start,int end,int e)
{
	int n=end-start;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(a[mid]>e&&(a[mid]>a[mid+1]||mid==n))
			return mid;
		else if(a[mid]<e)
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
}
int bsearch(vector<int>&a,int start,int end,int e)
{
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(a[mid]==e)
			return mid;
		else if(a[mid]>e)
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
}
int findElement(vector<int>&a,int e)
{
	int n=a.size();
	int actualLast=findLast(a,0,n-1,a[n-1]);
	int start=0,end=n-1,res=-1;
	if(actualLast!=-1)
	{
		if(e>=a[0])
			end=actualLast;
		else
			start=actualLast+1;
		res=bsearch(a,start,end,e);
	}
	else
	{
		res=bsearch(a,start,end,e);
	}
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
	int n,e;	
	cin>>n>>e;
	vi a(n);
	for(auto &x:a)
		cin>>x;
	int ind=findElement(a,e);
	cout<<ind<<"\n";
}