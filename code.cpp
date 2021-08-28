#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long

typedef pair<int,int> ii;
void solve();
void swap(int* a,int* b)
{
	int temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}

int randPartition(int a[],int l,int r)
{
	int n = r-l+1; 
    int pivot = rand() % n; 
    swap(&a[l + pivot], &a[r]); 
	pivot=a[r];
	int i=l;
	for(int j=i;j<r;j++)
	{
		if(a[j]<=pivot)
		{
			swap(&a[i],&a[j]);
			i++;
		}
	}
	swap(&a[i],&a[r]);
	return i;
}


int kthMin(int a[], int l, int r, int k)
{
    if(l<=r)
    {
    	int pos=randPartition(a,l,r);
    	
    	if(pos==k-1)
    		return a[pos];
    	if(pos>k-1)
    		return kthMin(a,l,pos-1,k);
    	return kthMin(a,pos+1,r,k);
    }

    return mod;
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
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int min=kthMin(a,0,n-1,k);
	cout<<min<<"\n";
	
}