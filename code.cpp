#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
void rearrangeAlternate(int a[],int n)
{
	int maxi=n-1;
	int mini=0;
	int max=a[maxi]+1;

	for(int i=0;i<n;i++)
	{
		if((i&1)==0)
		{
			a[i]+=(a[maxi]%max)*max;
			maxi--;
		}
		else
		{
			a[i]+=(a[mini]%max)*max;
			mini++;
		}
	}
	for(int i=0;i<n;i++)
	{
		a[i]=a[i]/max;
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

	rearrangeAlternate(a,n);

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

}