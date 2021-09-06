#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
string countAndSay(int n) {
    if(n==1)
        return "1";
    
    string s=countAndSay(n-1);
    int count=1,i=1;
    int l=s.length();
    string res="";
    
    while(i<l)
    {
        if(s[i]==s[i-1])
            count++;
        else
        {
            string c=to_string(count);
            res+=c;
            res+=s[i-1];
            count=1;
        }
        i++;
    }
    string c=to_string(count);
    res+=c;
    res+=s[i-1];
    
    return res;
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
	cout<<countAndSay(n)<<"\n";
}