#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve(); 
void spiraltravelmatrix(int** a,int n)
{
	int rstart=0,rend=n-1;
	int cstart=0,cend=n-1;
	while(rstart<=rend&&cstart<=cend)
	{
		int k=cstart;
		while(k<=cend)
		{
			cout<<a[rstart][k]<<" ";
			k++;
		}
		cout<<"\n";
		rstart++;
		k=rstart;
		while(k<=rend)
		{
			cout<<a[k][cend]<<" ";
			k++;
		}
		cout<<"\n";
		cend--;
		k=cend;
		while(k>=cstart)
		{
			cout<<a[rend][k]<<" ";
			k--;
		}
		cout<<"\n";
		rend--;
		k=rend;
		while(k>=rstart)
		{
			cout<<a[k][cstart]<<" ";
			k--;
		}
		cout<<"\n";
		cstart++;
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

	spiraltravelmatrix(a,n);

	

}