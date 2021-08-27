#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

int josephus(int n, int k)
{
    if(n==1)
    	return 1;
    return (josephus(n-1,k)+k-1)%n+1;
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
	int n,k;
	cin>>n>>k;
	cout<<josephus(n,k)<<"\n";
}