#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
void rotateClockwise(int** a,int n)
{
	for(int i=0;i<n/2;i++)
	{
		for(int j=i;j<n-1-i;j++)
		{
			int temp=a[i][j];
			a[i][j]=a[n-1-j][i];
			a[n-1-j][i]=a[n-i-1][n-1-j];
			a[n-i-1][n-1-j]=a[j][n-1-i];
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
	int* a[n];
	
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			a[i][j]=j+i*n+1;
		}
	}

	rotateClockwise(a,n);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}

}