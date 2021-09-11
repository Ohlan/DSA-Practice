#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int FindMaxSum(vi &a, int n)
    {
        int exc=0,inc=a[0];
        int excn;
        for(int i=1;i<n;i++)
        {
            excn=max(inc,exc);
            inc=exc+a[i];
            exc=excn;
        }
       return max(inc,exc);
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
    cout<<FindMaxSum(a,n)<<"\n";
	
}