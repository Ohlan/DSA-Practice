#include<bits/stdc++.h>
using namespace std;
void solve(void);
void rec1_N(int n)
{
	if(n>0)
	{
		rec1_N(n-1);
		cout<<n<<" ";
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
		cout<<"\n";
	}
	return 0;
}
void solve()
{
	int n=5;
//	cin>>n;
	rec1_N(n);
}