#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
void solve();
vi getMaxWeights(int n,int k,vi weights)
{
	vi res;
	dq q;
	for(int i=1;i<=k&&i<n;i++)
	{
		while((!q.empty())&&(weights[q.back()]<=weights[i]))
			q.pop_back();
		q.push_back(i);
	}
	if(!q.empty())
		res.push_back(q.front());

	int i=1,j=k+1;
	while(i<n-1)
	{
		while ((!q.empty()) && q.front() <= i)
            q.pop_front();

        int ind=min(j,n-1);
        while ((!q.empty()) && weights[ind] >= weights[q.back()])
            q.pop_back();
 
        q.push_back(ind);
        res.push_back(q.front());
        i++;
        j++;
	}
	res.push_back(-1);
	return res;
}
ll getMaxTaste(int n,int k,vi weights,vi taste)
{
	ll ans=taste[n-1];
	if(n==1)
		return ans;
	vi w=getMaxWeights(n,k,weights);
	int i=n-2;
	unordered_map<int,ll>mp;
	while(i>=0)
	{
		ll curr=0;
		int j=i;
		while(j!=-1)
		{
			if(mp.count(j)!=0)
			{
				curr+=mp[j];
				break;
			}
			curr+=taste[j];
			j=w[j];
		}
		mp[i]=curr;
		if(curr>ans)
			ans=curr;
		i--;
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
	int n,k;
	cin>>n>>k;
	vi weights(n);
	vi taste(n);
	for(auto &x:weights)
	{
		cin>>x;
	}
	for(auto &x:taste)
	{
		cin>>x;
	}
	
	
	ll maxTaste=getMaxTaste(n,k,weights,taste);
	cout<<maxTaste<<"\n";
}
