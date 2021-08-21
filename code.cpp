#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MIN -1000000
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
int findwater(int a[],int n)
{
	int lmax=0,rmax=0,low=0,high=n-1,res=0;
	while(low<=high)
	{
		if(a[low]<a[high])
		{
			if(a[low]>lmax)
				lmax=a[low];
			else
				res+=lmax-a[low];
			low++;
		}
		else
		{
			if(a[high]>rmax)
				rmax==a[high];
			else
				res+=rmax-a[high];
			high--;
		}
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
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	cout<<findwater(a,n)<<"\n";

}