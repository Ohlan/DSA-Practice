#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
typedef struct node
{
	int data;
	vector<node> components;
	node(){}
	node(int data)
	{
		this->data=data;
	}	
}node;
void solve();
void nextPermutation(vector<int>& a) 
{
    int i,n=a.size();
    for(i=n-1;i>0;i--)
    {
        if(a[i]>a[i-1])
            break;
    }
    if(i==0)
        sort(a.begin(),a.end());
    else
    {
        int min=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]>a[i-1]&&a[j]<a[min])
                min=j;
        }
        int temp=a[min];
        a[min]=a[i-1];
        a[i-1]=temp;
        sort(a.begin()+i,a.end());
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
	vi a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	nextPermutation(a);
	for(auto x:a)
		cout<<x<<" ";
	cout<<"\n";


}