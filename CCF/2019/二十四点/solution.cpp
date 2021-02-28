#include<cmath>
#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

inline int calculate(int x,int y,char op)
{
    switch (op)
    {
        case '+': return x+y;
        case '-': return x-y;
        case 'x': return x*y;
        case '/': return x/y;
        default:
            return 0;
    }
}

inline bool isright(string s)
{
    stack<int> res;
    stack<char> op;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
            res.push(s[i]-'0');
        else if (s[i]=='+' || s[i]=='-')
        {
            if(op.empty())
                op.push(s[i]);
            else
            {
                char now = op.top();
                if(now == 'x'||now=='/')
                {
                    op.pop();
                    int b = res.top();
                    res.pop();
                    int a = res.top();
                    res.pop();
                    int ans = calculate(a,b,now);
                    res.push(ans);
                }
                op.push(s[i]);
            }
        }
        else if(s[i]=='x'||s[i]=='/')
        {
            if(op.empty())
                op.push(s[i]);
            else
            {
                char now = op.top();
                if(now == 'x'||now=='/')
                {
                    op.pop();
                    int b = res.top();
                    res.pop();
                    int a = res.top();
                    res.pop();
                    int ans = calculate(a,b,now);
                    res.push(ans);
                }
                op.push(s[i]);
            }
        }
    }

    while (!op.empty())
    {
        char now = op.top();
        op.pop();
        int b = res.top();
        res.pop();
        int a = res.top();
        res.pop();
        int ans = calculate(a,b,now);
        res.push(ans);
    }

    // cout<<(res.size()==1)<<endl;
    // cout<<res.top()<<endl;
    return res.top()==24;
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(isright(s))
            cout<<"Yes"<<endl;
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}