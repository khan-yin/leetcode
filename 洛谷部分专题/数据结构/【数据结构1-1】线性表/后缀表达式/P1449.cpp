#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
using namespace std;
stack<int> number;

int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        int k=i;
        int num=0;
        if(str[k]=='@')
            break;
        if(str[k]=='+')
        {
            int a = number.top();
            number.pop();
            int b = number.top();
            number.pop();
            number.push(b+a);
        }
        else if(str[k]=='-')
        {
            int a = number.top();
            number.pop();
            int b = number.top();
            number.pop();
            number.push(b-a);
        }
        else if(str[k]=='*')
        {
            int a = number.top();
            number.pop();
            int b = number.top();
            number.pop();
            number.push(b*a);
        }
        else if(str[k]=='/')
        {
            int a = number.top();
            number.pop();
            int b = number.top();
            number.pop();
            number.push(b/a);
        }
        else
        {
            while(str[k]>='0'&&str[k]<='9'&&str[k]!='.')
            {
                num=num*10+str[k]-'0';
                k++;
            }
            number.push(num);
            i=k;
        }
    }
    cout<<number.top()<<endl;
    return 0;
}