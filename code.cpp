#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000000
typedef pair<int,int> ii;
void solve();

vector<long long> nextSmallerElementL2R(vector<long long> a, int n)
{
    stack<long long> s; 
    if(n>=1)
        s.push(a[0]);
    map<long long, long long> mp;
    for(int i=1;i<n;i++)
    {
        if(a[i]>=s.top())
            s.push(a[i]);
        else
        {
            while(s.empty()!=true&&s.top()>a[i])
            {
               mp[s.top()]=i;
                s.pop();
            }
            s.push(a[i]);
        }
    }
    while(s.empty()!=true)
    {
        mp[s.top()]=n;
        s.pop();
    }
    vector<long long> res(n);
    for(int i=0;i<n;i++)
    {
        res[i]=mp[a[i]];
    }
    return res;
}

vector<long long> nextSmallerElementR2L(vector<long long> a, int n)
{
    stack<long long> s; 
    if(n>=1)
        s.push(a[n-1]);
    map<long long, long long> mp;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>=s.top())
            s.push(a[i]);
        else
        {
            while(s.empty()!=true&&s.top()>a[i])
            {
               mp[s.top()]=i;
                s.pop();
            }
            s.push(a[i]);
        }
    }
    while(s.empty()!=true)
    {
        mp[s.top()]=-1;
        s.pop();
    }
    vector<long long> res(n);
    for(int i=0;i<n;i++)
    {
        res[i]=mp[a[i]];
    }
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
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(auto &x:a)
		cin>>x;
	vector<ll> b=nextSmallerElementL2R(a,n);
	vector<ll> c=nextSmallerElementR2L(a,n);
	ll max=0,curr=0,i=0;

	for(auto x:a)
	{
		curr=x*(b[i]-c[i]-1);
		if(curr>max)
			max=curr;
		i++;
	}
	cout<<max<<"\n";
}