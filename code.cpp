#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
void swap(vi &a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void threeWayPartition(vector<int>& arr,int a, int b)
{
	int n=arr.size();
	int i=0;
	for(int j=0;j<n;j++)
	{
		if(arr[j]<a)
		{
			swap(arr,i,j);
			i++;
		}
	}
	int k=i;
	i=n-1;
	for(int j=n-1;j>=k;j--)
	{
		if(arr[j]>b)
		{
			swap(arr,i,j);
			i--;
		}
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
    threeWayPartition(a,44,62);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}