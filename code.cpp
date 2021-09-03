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
        stack<int> s;
        for(int i=0;i<n;i++)
            s.push(i);
        
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,a,b))
                s.push(b);
            else
                s.push(a);
            
        }
        int c=s.top();
        
        for(int i=0;i<n;i++)
        {
            if((i!=c)&&(knows(M,i,c)==false||knows(M,c,i)))
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