#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve();
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// int t;
	// cin>>t;
	// while(t--)
	// 	solve();
	solve();
	return 0;
}
void solve()
{
	string s;
	cin>>s;
	int max=1,count=1,n=s.length();
	for(int i=1,j=0;i<n;i++)
	{
		if(s[j]==s[i])
			count++;
		else
		{
			if(count>max)
				max=count;
			count=1;
			j=i;
		}
	}
	if(count>max)
		max=count;
	cout<<max<<"\n";
}