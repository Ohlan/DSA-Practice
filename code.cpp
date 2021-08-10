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
	int j=0;
	for(int i=0;i<n;i++)
		if(a[i]<0)
			if(i!=j)
			{
				int temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				j++;
			}
	
	for(auto x:a)
		cout<<x<<" ";
}