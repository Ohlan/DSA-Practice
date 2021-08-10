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
	int i=0,j=n-1;
	while(i<j)
	{
		while(a[i]<0&&i<n)
			i++;
		while(a[j]>=0&&j>=0)
			j--;
		if(i<j)	
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	for(auto x:a)
		cout<<x<<" ";
}