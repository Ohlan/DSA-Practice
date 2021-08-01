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
int noofways(int n)
{
	if(n<0)
	{
		return 0;
	}
	if(n==0)
		return 1;
	return noofways(n-1)+noofways(n-2)+noofways(n-3);

}
// void subsets(vi &a,vi subset,int i)
// {
// 	if(i==a.size())
// 	{
// 		print(subset);
// 		return;
// 	}
// 	vi s=subset;
// 	s.push_back(a[i]);
// 	subsets(a,s,i+1);
// 	subsets(a,subset,i+1);
// }
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
	int ans=0;
	ans=noofways(n);
	cout<<ans<<"\n";	
}