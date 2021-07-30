#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solve();
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	// solve();
	return 0;
}
void solve()
{
	int w,h;
	cin>>w>>h;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int w1,h1;
	cin>>w1>>h1;
	if(w-(x2-x1)<w1&&h-(y2-y1)<h1)
		cout<<"-1\n";
	else
	{
		double x=(max(x1,w-x2));
		double y=(max(y1,h-y2));
		if(x<w1)
			x=w1-x;
		else
			x=0;
		if(y<h1)
			y=h1-y;
		else
			y=0;
		if(w-(x2-x1)<w1)
			cout<< fixed << setprecision(9) <<y<<"\n";
		else if(h-(y2-y1)<h1)
			cout<< fixed << setprecision(9) <<x<<"\n";
		else
			cout<< fixed << setprecision(9) <<min(x,y)<<"\n";


		//cout<< fixed << setprecision(9) <<sqrt((x*x)+(y*y))<<"\n";
	}
	
}