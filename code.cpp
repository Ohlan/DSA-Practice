#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
long long maxProduct(vector<int> a, int n)
{
    long long maxv=a[0],minv=a[0],maxp=a[0];
    for(int i=1;i<n;i++)
    {
    	if(a[i]<0)
    		swap(maxv,minv);
    	maxv=max((long long)a[i],maxv*a[i]);
    	minv=min((long long)a[i],minv*a[i]);
    	maxp=max(maxp,maxv);

    }
    return maxp;
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
    cout<<maxProduct(a,n);
    cout<<"\n";
}