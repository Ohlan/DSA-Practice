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
    int i=0,j=n-1;
    long long curr1=1,curr2=1,left=0,right=0;
    while(i<n)
    {
        curr1*=a[i];
        left=max(curr1,left);
        if(curr1==0)
            curr1=1;
        curr2*=a[j];
        right=max(curr2,right);
        if(curr2==0)
            curr2=1;
        i++;j--;
    }
    return max(left,right);
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