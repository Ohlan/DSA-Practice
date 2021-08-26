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
ii getMax(node mainc,node &max)
{
	if(mainc.components.size()==0)
	{
		if(mainc.data>max.data)
			max=mainc;
		return make_pair(mainc.data,1);
	}
	int sum=0,parts=0;double sp=0;
	for(int i=0;i<mainc.components.size();i++)
	{
		ii p=getMax(mainc.components[i],max);
		double speed=(p.first)/(p.second);
		if(speed>sp)
		{
			max=mainc.components[i];
			sp=speed;
		}
		sum+=p.first;
		parts+=p.second;
	}
	sum+=(mainc.data);parts++;
	double speedm=sum/parts;
	if(speedm>sp)
	{
		max=mainc;
		sp=speedm;
	}
	return make_pair(sum,parts);

}
node* getFastestComponent(node* root)
{
	if(root)
	{
		node mainc=(*root);
		node max=node(0);
		
		ii p=getMax(mainc,max);
		node* res=&max;
		return res;
	}
	return NULL;
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
	node* root=new node(200);
	node rl(120);
	node rr(180);
	node a,b,c,d,e,f;
	a=node(110);
	b=node(20);
	c=node(30);
	d=node(180);
	e=node(150);
	f=node(80);
	rl.components={a,b,c};
	rr.components={d,e,f};
	root->components={rl,rr};

	node* ans=getFastestComponent(root);
	cout<<ans->data<<" "<<ans->components.size();


}