#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();

bool findPair(vi a, int size, int n){
    sort(a.begin(), a.end());
    int i=0,j=0;
    while(i<n&&j<n)
    {
        if(a[j]-a[i]==n&&i!=j)
            return true;
        else if(a[j]-a[i]<n)
            j++;
        else
        {
            i++;
        }
    }
    return false;
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
	cout<<findPair(a,n,20)<<"\n";
}