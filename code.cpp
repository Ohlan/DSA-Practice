#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long

typedef pair<int,int> ii;
void solve();
int getpairs(int a[],int n,int k)
{
	unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(k - a[i]) != m.end()) {
            count += m[k - a[i]];
        }
        m[a[i]]++;
    }
    return count;   
    
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
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int count=getpairs(a,n,k);
	cout<<count<<"\n";
	
}