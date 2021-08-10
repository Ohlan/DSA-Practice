#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	// solveBT();
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	vi a(n);
	for(auto &x:a)
		cin>>x;
	int repeated,missing;
	for(int i=0;i<n;i++)
	{
		int temp=a[abs(a[i])-1];
		if(temp<0)
		{
			repeated=abs(a[i]);
		}
		a[abs(a[i])-1]=-a[abs(a[i])-1];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		{
			missing=i+1;
		}
	}
	cout<<repeated<<" "<<missing<<"\n";
}