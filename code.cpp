#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000000
typedef pair<int,int> ii;
void solve();

int count(string s){
    int ans=0;
    int n=s.length();
    int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
            a++;
        else
            b++;
        if(a<b)
        {
            s[i]='A';
            a++;
            b--;
            ans++;
        }
        
    }
    a=0;b=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='A')
            a++;
        else
            b++;
        if(a>b)
        {
            s[i]='B';
            a--;
            b++;
            ans++;
        }
            
    }
    return ans;
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
	cout<<count(s)<<"\n";
}