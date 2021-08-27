#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

bool find(int n, int m)
{
    if(n%m==0)
        return false;
    if(n<m)
        return true;
    n=n-(n/m);
    return find(n,m+1);
}

bool isLucky(int n) {
    return find(n,2);
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
	int a;
	cin>>a;
	cout<<isLucky(a)<<"\n";
}