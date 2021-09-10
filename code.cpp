#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

int majorityElement(vi a, int n)
{
    int m=0,count=1;    
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[m])
            count++;
        else
            count--;
        if(count==0)
        {
            m=i;
            count=1;
        }
    }
    m=a[m],count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==m)
            count++;
    }
    if(count>n/2)
        return m;
    else
        return -1;
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
	vi a(n);
	for(auto &x:a)
		cin>>x;
	cout<<majorityElement(a,n)<<"\n";
}