#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
int merge(int arr[], int start,int mid,int end)
{
	int l=end-start+1;
	int a[l];
	int i=start,j=mid+1,k=0;
	int c=0;
	while(i<=mid&&j<=end)
	{
		if(arr[i]<=arr[j])
		{
			a[k]=arr[i];
			i++;k++;

		}
		else
		{
			a[k]=arr[j];
			j++,k++;
			c+=mid-i+1;
		}
	}
	while(i<=mid)
	{
		a[k]=arr[i];
		i++;k++;
	}
	while(j<=end)
	{
		a[k]=arr[j];
		j++,k++;
	}
	k=0;
	for(int p=start;p<=end;p++,k++)
		arr[p]=a[k];
	return c;
}


int inversionCount(int arr[], int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		int c1=inversionCount(arr,start,mid);
		int c2=inversionCount(arr,mid+1,end);
		int c3=merge(arr,start,mid,end);
		return c1+c2+c3;
	}
	return 0;		
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
    cout<<inversionCount(a,0,n-1)<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}