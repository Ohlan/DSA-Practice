#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
void solve();
void print(vi &a)
{
	for(auto x:a)
		cout<<x<<" ";
	cout<<"\n";
}
// void nowofways(int n, int step, int &ans)
// {
// 	if(step>=n)
// 	{
// 		if(step==n)
// 			ans++;
// 		return;
// 	}
// 	nowofways(n,step+1,ans);
// 	nowofways(n,step+2,ans);
// 	nowofways(n,step+3,ans);

// }
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
	ll y,x;
	cin>>y>>x;
	ll ans=1;
	if(x>=y)
	{
		if(x%2!=0)
		{
			ll temp=x;
			x=y;
			y=temp;
			ans=y*y+1-x;
		}
		else
			ans=x+(x-1)*(x-2)+(y-1);
	}
	else
	{
		if(y%2!=0)
		{
			ll temp=x;
			x=y;
			y=temp;
			ans=x+(x-1)*(x-2)+(y-1);
		}
		else
			ans=y*y+1-x;
	}
	cout<<ans<<"\n";
	
}