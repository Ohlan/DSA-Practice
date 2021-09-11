#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1 )
            count+= 1;
        a = a>>1;
    }
    return count;
}
bool compare(int a,int b)
{
	return countBits(a)>countBits(b);
}
void sortBySetBitCount(int arr[], int n)
{
	sort(arr,arr+n,compare);
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

	int a[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sortBySetBitCount(a,n);
    for(int i=0;i<n;i++)
    	cout<<a[i]<<" ";
    cout<<"\n";
}