#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
typedef struct half
{
    int val;
    int first;
    int second;
}half;
bool compare(half &p1,half &p2)
{
    return (p1.val<=p2.val);
}
bool noCommon(half a, half b)
{
    if (a.first == b.first || a.first == b.second
        || a.second == b.first || a.second == b.second)
        return false;
    return true;
}
vector<vector<int> > fourSum(vector<int> &a, int sum)
{
    int n=a.size();
    int l=(n*(n-1))/2,k=0;
    half pairs[l];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            pairs[k].val=a[i]+a[j];
            pairs[k].first=i;
            pairs[k].second=j;
            k++;
        }
    }

    sort(pairs,pairs+l,compare);
    vector<vector<int> > res;
    int i=0,j=l-1;
    while(i<j)
    {
        if(pairs[i].val+pairs[j].val==sum)
        {
            
            int x=pairs[i].first;
            int y=pairs[i].second;
            int c=pairs[j].first;
            int d=pairs[j].second;
            if(noCommon(pairs[i], pairs[j]))
                res.push_back({a[x],a[y],a[c],a[d]});
            // i++;
            j--;
        }
        else if(pairs[i].val+pairs[j].val<sum)
        {
            i++;
        }
        else
            j--;

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
	int n;	
	cin>>n;
	vi a(n);
	for(auto &x:a)
		cin>>x;
	vector<vector<int> > res=fourSum(a,23);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
}