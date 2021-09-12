#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int search(vi a,int n,int x)
{
	int i=0,j=n;
	while(i<=j)
	{
		int mid=(i+j)/2;
		if((a[mid]>=a[mid-1]||mid==0)&&(a[mid]>=a[mid+1]||mid==n))
			return mid;
		else if(a[mid]<x)
		{
			j=mid-1;
		}
		else
		{
			i=mid+1;
		}
	}
	return -1;
}

int findPivot(vi a,int n)
{
	if(a[0]<a[n-1])
	{
		cout<<"array is not rotated...\n";
		return n-1;
	}
	int ind=search(a,n-1,a[n-1]);
	return ind;
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
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<findPivot(a,n)<<"\n";

}