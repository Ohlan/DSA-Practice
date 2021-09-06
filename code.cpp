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
    int max=1,ind=0;
    int low,high;
    for(int i=1;i<n;i++)
    {
    	low=i-1,high=i;
    	while(low>=0&&high<n&&s[low]==s[high])
    	{
    		low--;high++;
    	}
    	low++;high--;
    	if(low<high)
    	{
    		if(high-low+1>max)
    		{
    			max=high-low+1;
    			ind=low;
    		}
    	}
    	low=i-1;high=i+1;
    	while(low>=0&&high<n&&s[low]==s[high])
    	{
    		low--;high++;
    	}
    	low++;high--;
    	if(high-low+1>max)
    	{
    		max=high-low+1;
    		ind=low;
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