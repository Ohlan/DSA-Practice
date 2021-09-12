#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

int smallestSubWithSum(vi a, int n, int x)
{
	int i=0,j=0,sum=0,min=n;
	while(j<n)
	{
		while(sum<=x&&j<n)
		{
			sum+=a[j++];
		}
		while(sum>x)
		{
			if(j-i<min)
				min=j-i;
			sum-=a[i++];
		}
	}
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