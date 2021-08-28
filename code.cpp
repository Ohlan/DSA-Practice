#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long

typedef pair<int,int> ii;
void solve();
bool subArrayExists(int a[], int n)
{
    map<int,int> mp;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(mp[sum]==1||sum==0)
            return true;
        
        mp[sum]=1;
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
	
	cout<<subArrayExists(a,n)<<"\n";
	
}