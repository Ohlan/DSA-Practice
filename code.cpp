#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000000
typedef pair<int,int> ii;
void solve();
int longestValidSubstring(string s)
{
	int n=s.length();
	int l=0,r=0,maxi=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
			l++;
		else
			r++;
		if(l==r)
			maxi=max(maxi,2*r);
		else if(r>l)
		{
			l=0;r=0;
		}
	}
	l=r=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='(')
			l++;
		else
			r++;
		if(l==r)
			maxi=max(maxi,2*l);
		else if(l>r)
		{
			l=0;r=0;
		}
	}
	return maxi;
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
	string s;
	cin>>s;
	cout<<longestValidSubstring(s)<<"\n";
	
}