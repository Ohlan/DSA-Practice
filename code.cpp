#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int gcd(int a,int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
void leftRotate(vi &arr, int d, int n)
{
    /* To handle if d >= n */
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;
 
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
 
            if (k == i)
                break;
 
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
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
	int n,m;
	cin>>n>>m;
	vi a(n);
	for(auto &x:a)
		cin>>x;

	leftRotate(a,m,n);
	// while(rep--)
	// {
	// 	for(int j=0;j<gcd;j++)
	// 	{
	// 		int temp=a[0];
	// 		for(int i=j;i<n-gcd;i+=gcd)
	// 		{
	// 			a[icd]=a[i];
	// 		}
	// 		a[n-1]=temp;
	// 	}
	// }

	for(auto x: a)
		cout<<x<<" ";
	cout<<"\n";
}