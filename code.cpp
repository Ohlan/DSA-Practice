#include<bits/stdc++.h>
using namespace std;
// #define mod 1000000007
#define INF INT_MAX
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
void solve();
int findlis(vector<int> lisWithMinTail,int end,int k)
{
	int start=0;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(lisWithMinTail[mid]>=k&&(mid==0||lisWithMinTail[mid-1]<k))
			return mid;
		else if(lisWithMinTail[mid]<k)
			start=mid+1;
		else
			end=mid-1;
	}
	return 0;
}
int lisTail(vi a,int n)
{
	if(n==0)
		return 0;
	vector<int> lisWithMinTail(1);
	lisWithMinTail[0]=1;
	int j,i;
	for(i=1,j=0;i<n;i++)
	{
		if(a[i]>lisWithMinTail[j])
		{
			lisWithMinTail.push_back(a[i]);
			j++;
		}
		else
		{
			int ind=findlis(lisWithMinTail,j,a[i]);
			lisWithMinTail[ind]=a[i];
		}
		
	}
	return j+1;
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
	
	cout<<lisTail(a,n)<<"\n";
}
