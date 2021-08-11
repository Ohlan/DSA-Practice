#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();
bool compare(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
{
	return p1.first.second<p2.first.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	// solveBT();
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	vector<pair<pair<int,int>,int>> a(n);
	for(int i=0;i<n;i++)
	{
		int x,y,j;
		cin>>x>>y>>j;
		a[i]=make_pair(make_pair(x,y),j);
	}
	sort(a.begin(),a.end());
	for(auto x:a)
	{
		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
	}
	// cout<<"\n";
	// sort(a.begin(),a.end(),greater<int>());
	// for(auto x:a)
	// {
	// 	cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
	// }
	cout<<"\n";
	sort(a.begin(),a.end(),compare);
	for(auto x:a)
	{
		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
	}


}