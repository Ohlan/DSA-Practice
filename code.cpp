#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

int increaseByMin(vi &a,int n)
{
	int min=mod;
	for(auto i:a)
		if(i<min)
			min=i;
	min=abs(min);
	for(int i=0;i<n;i++)
		a[i]+=min;
	return min;
}

int smallestSubWithSum(vi a, int n, int x)
{
	int val=increaseByMin(a,n);
	int i=0,j=0,sum=0,min=n+1;
	while(j<n)
	{
		while(sum<=x&&j<n)
		{
			sum+=a[j++];
			sum-=val;
		}
		while(sum>x)
		{
			if(j-i<min)
				min=j-i;
			sum-=a[i++];
			sum+=val;
		}
	}
	if(min==n+1)
		return -1;
	return min;
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
    cout<<smallestSubWithSum(a,n,7)<<"\n";
    
}