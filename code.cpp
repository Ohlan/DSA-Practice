#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

int searchWithDiffK(vi a, int n,int k, int x)
{
    int i=0;
    while(i<n)
    {
        if(a[i]==x)
            return i;
        i=i+(max(1,abs(a[i]-x)/k));
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
	
	return 0;
}
void solve()
{
	int n;	
	cin>>n;
	vi a(n);
	for(auto &x:a)
		cin>>x;
	cout<<searchWithDiffK(a,n,20,60)<<"\n";
}