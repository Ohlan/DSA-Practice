#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define MIN -1000000
typedef pair<int,int> ii;
void solve();
int precedence(char c)
{
	if(c=='^')
		return 3;
	else if(c=='/'||c=='*')
		return 2;
	else if(c=='-'||c=='+')
		return 1;
	else
		return 0;
}
string infixToPostfix(string infix)
{
	string res;
	stack<char> s;
	s.push('a');
	int l=infix.length();
	for(int i=0;i<l;)
	{
		if(infix[i]>='0'&&infix[i]<='9')
		{
			int j=i;
			string num;
			while(infix[j]<='9'&&infix[j]>='0'&&j<l)
			{
				num+=infix[j];
				j++;
			}
			res+=num;
			res+='$';
			i=j;
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
			i++;
		}
		else if(infix[i]==')')
		{
			while(s.top()!='('&&s.top()!='a')
			{
				char op=s.top();
				res+=op;
				s.pop();
			}
			if(s.top()!='a')	
				s.pop();
			i++;

		}
		else
		{
			while(precedence(s.top())>=precedence(infix[i])&&s.top()!='a')
			{
				char op=s.top();
				res+=op;
				s.pop();

			}
			s.push(infix[i]);
			i++;
		}
		
	}
	while(s.top()!='a')
	{
		res+=s.top();
		s.pop();
	}

	return res;
}
int postfixEval(string postfix)
{
	int operand;
	stack<int> s;
	
	int i=0,l=postfix.length();
	while(i<l)
	{
		if(postfix[i]>='0'&&postfix[i]<='9')
		{
			int j=i;
			string num;
			while(postfix[j]!='$'&&j<l)
			{
				num+=postfix[j];
				j++;
			}
			j++;
			i=j;
			operand=stoi(num);
			s.push(operand);
			
		}
		else
		{
			int op1=0,op2=0;
			char optr=postfix[i];
			op1=s.top();
			s.pop();
			op2=s.top();
			s.pop();
			switch(optr)
			{
				case '^':
				{
					operand=pow(op2,op1);
					s.push(operand);
					break;
				}
				case '/':
				{
					operand=op2/op1;
					s.push(operand);
					break;
				}
				case '*':
				{
					operand=op2*op1;
					s.push(operand);
					break;
				}
				case '+':
				{
					operand=op2+op1;
					s.push(operand);
					break;
				}
				case '-':
				{
					operand=op2-op1;
					s.push(operand);
				}

			}
			i++;
			
		}
	}
	operand=s.top();
	return operand;
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
	string infix;
	cin>>infix;
	string postfix=infixToPostfix(infix);
	cout<<postfix<<"\n";
	int ans=postfixEval(postfix);
	cout<<ans<<"\n";
}