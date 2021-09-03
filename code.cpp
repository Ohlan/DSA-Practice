#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000000
typedef pair<int,int> ii;
void solve();

void insertAtpos(stack<int>&s,int a)
{
    if(s.empty())
    {
        s.push(a);
    }
    else
    {
        if(s.top()<a)
        {
            s.push(a);
        }
        else
        {
            int b=s.top();
            s.pop();
            insertAtpos(s,a);
            s.push(b);
        }
    }
}
void sortStack(stack<int>&s)
{
    if(s.empty())
        return;
    
    int a=s.top();
    s.pop();
    sortStack(s);
    insertAtpos(s,a);
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
	stack<int> s;
	int n;
	cin>>n;
	for(int i=n;i>=0;i--)
		s.push(i);
	
	sortStack(s);

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"\n";
}