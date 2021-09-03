#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000000
typedef pair<int,int> ii;
void solve();


bool knows(vector<vector<int> >& M,int a,int b)
{
    return M[a][b];
}
int findCelebrity(vector<vector<int> >& M, int n)
{
	int i=0,j=n-1;
	while(i<j)
	{
		if(knows(M,i,j))
			i++;
		else
			j--;
	}

	int c=i;
	for(int i=0;i<n;i++)
	{
		if(i!=c)
			if(knows(M,c,i)||!knows(M,i,c))
				return -1;
	}
	return c;
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
	vector<vector<int>> M{{0, 0, 1, 0},
			             {0, 0, 1, 0},
			             {0, 0, 0, 0},
			             {0, 0, 1, 0}};
    int n = 4;
    int id = findCelebrity(M,n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
}