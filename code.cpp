#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int maxPalindromeSubstr(string s) {
    int n=s.length();
    bool palin[n][n];
    for(int i=0;i<n;i++)
    {
    	palin[i][i]=1;
    }
    int max=1,ind=0;
    for(int i=0;i<n-1;i++)
    {
    	if(s[i]==s[i+1])
    	{
    		palin[i][i+1]=1;
    		if(max==1)
    		{
    			max=2;
    			ind=i;
    		}
    	}
    	else
    		palin[i][i+1]=0;

    }
    for(int k=3;k<=n;k++)
    {
    	for(int i=0;i<n-k+1;i++)
    	{
    		int j=i+k-1;
    		if(palin[i+1][j-1]==1&&s[i]==s[j])
    		{
    			palin[i][j]=1;
    			if(k>max)
	    		{
	    			max=k;
	    			ind=i;
	    		}
    		}
    		else
    			palin[i][j]=0;
    	}
    }
    string res=s.substr(ind,max);
    cout<<res<<"\n";
    return max;
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
	cout<<"max length of palindrome substring:"<<maxPalindromeSubstr(s)<<"\n";
}