#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
typedef pair<int,int> ii;
void solve();
string s[10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void getres(int a[], int n,int i=0,string p="")
{
    
    for(int j=0;j<s[a[i]].length();j++)
    {
        p+=s[a[i]][j];
        if(i<n-1)
            getres(a,n,i+1,p);
        else
            cout<<p<<" ";
        p.pop_back();
    }
}
void possibleWords(int a[], int n)
{
    getres(a,n);
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
	possibleWords(a,n);
}