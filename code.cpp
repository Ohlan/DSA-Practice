#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000000
typedef pair<int,int> ii;
void solve();

void insertBottom(stack<int>& s,int e)
{
	if(s.empty())
		s.push(e);
	else
	{
		int a=s.top();
		s.pop();
		insertBottom(s,e);
		s.push(a);
	}
}
void reverseStack(stack<int>&s)
{
	if(s.empty())
		return;
	int a=s.top();
	s.pop();
	reverseStack(s);
	insertBottom(s,a);
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
	for(int i=1;i<=n;i++)
		s.push(i);
	
	reverseStack(s);

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<"\n";
}