#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000
typedef pair<int,int> ii;
void solve();


    bool areIsomorphic(string a, string b)
    {
        int n=a.length();
        int m=b.length();
        if(n!=m)
            return false;
            
        map<char,int>m1;
        map<char,int>m2;
        
        for(int i=0;i<n;i++)
        {
            if(m1.count(a[i])==0)
            {
                if(m2.count(b[i])!=0)
                    return false;
                else
                {
                    m1[a[i]]=i;
                    m2[b[i]]=i;
                }
            }
            else
            {
                if(b[m1[a[i]]]!=b[i])
                    return false;
                else
                {
                    m1[a[i]]=i;
                    m2[b[i]]=i;
                }
            }
        }
        return true;
    }

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll t;
	cin>>t;
	while(t--)
		solve();	
	return 0;
}

void solve()
{
	string a,b;
	cin>>a>>b;
	cout<<areIsomorphic(a,b)<<"\n";
	
}