#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
void swap(vector<int>&a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int minSwaps(vector<int>&a)
{
	vector<int>temp(a.begin(),a.end());
	sort(temp.begin(), temp.end());
	map<int,int>mp;int k=0;
	for(auto i:a)
	{
		mp[i]=k;
		k++;
	}
	int count=0;

	for(int i=0;i<k;i++)
	{
		if(a[i]!=temp[i])
		{
			int init=a[i];
			swap(a,i,mp[temp[i]]);
			mp[init]=mp[temp[i]];
			mp[temp[i]]=i;
			count++;
		}
		
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
	int n;	
	cin>>n;

	vi a(n);
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<minSwaps(a)<<"\n";
    
}