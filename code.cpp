#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();


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
	int a;
	cin>>a;
	int ans=0;
	if(a%4==0)
		ans=a;
	else if(a%4==3)
		ans=0;
	else if(a%4==1)
		ans=1;
	else
		ans=a+1;
	cout<<ans<<"\n";
}