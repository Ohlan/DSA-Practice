#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
long long countTriplets(long long a[], int n, long long sum)
    {
        sort(a,a+n);
        long long count=0;
        for(int i=0;i<n-1;i++)
        {
            long long j=i+1,k=n-1;
            while(j<k)
            {
                if(a[i]+a[j]+a[k]>=sum)
                    k--;
                else
                {
                    count+=k-j;
                    j++;
                }
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
	ll a[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<countTriplets(a,n,15)<<"\n";
	
}