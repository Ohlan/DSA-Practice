#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
void merge(int a1[], int a2[], int n, int m)
    {
        int i=0,j=0,k=0;
        int ma=max(a1[n-1],a2[m-1])+1;
        while(i<n&&j<m)
        {
            if((a1[i]%ma)>(a2[j]%ma))
            {
                if(k<n)
                {
                    a1[k]=(a2[j]%ma)*ma+a1[k];
                    j++;k++;
                }
                else
                {
                    a2[k-n]=(a2[j]%ma)*ma+a2[k-n];
                    j++;k++;
                }
            }
            else
            {
                if(k<n)
                {
                    a1[k]=(a1[i]%ma)*ma+a1[k];
                    i++;k++;
                }
                else
                {
                    a2[k-n]=(a1[i]%ma)*ma+a2[k-n];
                    i++;k++;
                }
                
            }
        }
        while(i<n)
        {
            if(k<n)
                {
                    a1[k]=(a1[i]%ma)*ma+a1[k];
                    i++;k++;
                }
                else
                {
                    a2[k-n]=(a1[i]%ma)*ma+a2[k-n];
                    i++;k++;
                }
        }
        while(j<m)
        {
            if(k<n)
                {
                    a1[k]=(a2[j]%ma)*ma+a1[k];
                    j++;k++;
                }
                else
                {
                    a2[k-n]=(a2[j]%ma)*ma+a2[k-n];
                    j++;k++;
                }
        }
        i=0,j=0;
        while(i<n)
        {    
            a1[i]=a1[i]/ma;i++;
        }
        while(j<m)
        {   
            a2[j]=a2[j]/ma;j++;
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
	int a[n],b[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    merge(a,b,n,n);
	for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}