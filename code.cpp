#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
void simpleSeive(int limit)
{
	vector<bool> flag(limit,true);

	for(int i=2;i*i<limit;i++)
	{
		if(flag[i]==true)	
			for(int j=i*i;j<limit;j+=i)
			{
				flag[j]=false;
			}
	}
	for(int i=2;i<limit;i++)
		if(flag[i]==true)
			cout<<i<<" ";
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
	int n;
	cin>>n;
	
	simpleSeive(n);
	cout<<"\n";
}