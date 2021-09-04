#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000000
typedef pair<int,int> ii;
void solve();
ll getLargestAreaHistogram(vector<ll> a, ll n)
{
	stack<ll> s;
	ll max_area=0;
	ll curr_area=0;
	ll i=0;
	while(i<n)
	{
		if(s.empty()||a[i]>=a[s.top()])
			s.push(i++);
		else
		{
			ll tp=s.top();
			s.pop();

			curr_area=a[tp]*(s.empty()?i:i-(s.top())-1);
			if(curr_area>max_area)
				max_area=curr_area;
		}
	}
	while(!s.empty())
	{
		ll tp=s.top();
		s.pop();

		curr_area=a[tp]*(s.empty()?i:i-s.top()-1);
		if(curr_area>max_area)
			max_area=curr_area;
		cout<<curr_area<<" ";
	}
	return max_area;
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
	
	cout<<getLargestAreaHistogram(a,n)<<"\n";
	
}