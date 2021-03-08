#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;
int main() 
{
	char a[1005];
	stack<int> n;
	stack<char> b; 
	cin>>a;
	int i=0;
	int m=0;
	int tex=0;
	while(a[i]!='@')
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			m=m*10+(a[i]-'0');
		}
		if(a[i]=='.')
		{
			n.push(m);
			m=0;
			i++; 
			continue;
		}
		if(a[i]=='+')
		{
			tex=n.top();
			n.pop();
			tex+=n.top();
			n.pop();
			n.push(tex); 
		}
		else if(a[i]=='-')
		{
			tex=n.top();
			n.pop();
			tex=n.top()-tex;
			n.pop();
			n.push(tex);
		}
		else if(a[i]=='*')
		{
			tex=n.top();
			n.pop();
			tex=n.top()*tex;
			n.pop();
			n.push(tex);
		}
		else if(a[i]=='/')
		{
			tex=n.top();
			n.pop();
			tex=n.top()/tex;
			n.pop();
			n.push(tex);
		}
		i++;
	}
	cout<<n.top();
	return 0;
}