#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int euclidianGCD(int a,int b)
{
	if(a==0)
		return b;
	return euclidianGCD(b%a,a);
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
	int n,m;
	cin>>n>>m;
	
	cout<<euclidianGCD(n,m)<<"\n";
}