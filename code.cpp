#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();
int partition(vi &a, int l, int r)
{
	int pivot=a[r];
	int i=l-1;
	for(int j=l;j<r;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}
void quicksort(vi &a, int l, int r)
{
	if(l<r)
	{
		int pi=partition(a, l, r);
		quicksort(a, l, pi-1);
		quicksort(a, pi+1, r);
	}
}
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
	quicksort(a,0,n-1);
	for(auto x:a)
		cout<<x<<" ";
	cout<<"\n";
}