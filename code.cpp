#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();
void print(vi &a)
{
	for(auto x:a)
		cout<<x<<" ";
	cout<<"\n";
}
void subsets(vi &a,vi subset,int i)
{
	if(i==a.size())
	{
		print(subset);
		return;
	}
	vi s=subset;
	s.push_back(a[i]);
	subsets(a,s,i+1);
	subsets(a,subset,i+1);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	// solve();
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	vi a(n);
	vi subset;
	for(auto &x:a)
		cin>>x;
	subsets(a,subset,0);	
}