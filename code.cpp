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
	if(a==0)
	{
		cout<<0<<"\n";
		return;
	}

	int count=0;
	while(a)
	{
		a>>=1;
		count++;
	}
	int ans=1;count--;
	while(count--)
	{
		ans<<=1;
	}

	cout<<ans<<"\n";
}