#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int findLongestConseqSubseq(vi a, int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[a[i]]++;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(mp.count(a[i]-1)==0)
		{
			int j=a[i];
			while(mp.count(j)!=0)
				j++;
			ans=max(ans,j-a[i]);
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
	int n;	
	cin>>n;

	vi a(n);
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<findLongestConseqSubseq(a,n);
    cout<<"\n";
}