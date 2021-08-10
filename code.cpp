#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();
int doUnion(vi a, int n, vi b, int m)  {
	set<int> st;
	for(auto x:a)
		st.insert(x);

	for(auto x:b)
		st.insert(x);

	return st.size();        
}
int doIntersection(vi a, int n, vi b, int m)
{
	set<int> st;map<int,int>mp;
	for(auto x:a)
		mp[x]=1;

	for(auto x:b)
		if(mp.count(x)!=0)
			st.insert(x);

	return st.size();
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
	int n,m;
	cin>>n>>m;
	vi a(n);
	for(auto &x:a)
		cin>>x;
	vi b(m);
	for(auto &x:b)
		cin>>x;
	cout<<doIntersection(a,n,b,m)<<"\n";
}