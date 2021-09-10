#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

vector<vector<int> > fourSum(vector<int> &a, int sum)
{
    int n=a.size();
    sort(a.begin(), a.end());
    
    vector<vector<int> > res;
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int rem=sum-(a[i]+a[j]);
            int k=j+1,l=n-1;
            while(k<l)
            {
                if(a[k]+a[l]==rem)
                {
                    res.push_back({a[i],a[j],a[k],a[l]});
                    k++,l--; 
                }
                else if(a[k]+a[l]<rem)
                {
                    k++;
                }
                else
                    l--;
            }
        }
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