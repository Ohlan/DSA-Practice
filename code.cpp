#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

void permute(string s,int i=0)
{
    if(i==s.length()-1)
    {
    	cout<<s<<" ";
    	return;
    }
    for(int j=i;j<s.length();j++)
    {
    	swap(s[i],s[j]);
    	permute(s,i+1);
    	swap(s[i],s[j]);
    }
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
	sort(s.begin(),s.end());
	permute(s);
	cout<<"\n";
}