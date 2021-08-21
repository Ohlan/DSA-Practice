#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MIN -1000000
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
bool findwater(int a[],int n)
{
	int x=0,y=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>=a[i-1])
			x++;
		else
			y++;
	}
	if(x==1||y==1)
	{
		if(a[n-1]<a[0])
			x++;
		else
			y++;
		if(x==1||y==1)
			return true;
	}
	return false;
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