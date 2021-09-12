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
int minSwap(vector<int> arr,int k)
{
	int n=arr.size();
	int count=0;
	for(int i=0;i<n;i++)
		if(arr[i]<=k)
			count++;
	int bad=0;
	for(int i=0;i<count;i++)
		if(arr[i]>k)
			bad++;
	int ans=bad;
	for(int i=0,j=count;j<n;j++,i++)
	{
		if(arr[i]>k)
			bad--;
		if(arr[j]>k)
			bad++;

		ans=min(ans,bad);
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
    cout<<minSwap(a,1)<<" ";
    cout<<"\n";
}