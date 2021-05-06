#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

const int N = 10010;

stack<int> num;
stack<char> op;


inline void eval()
{
    int b = num.top(); num.pop();
    int a=num.top(); num.pop();
    char c = op.top(); op.pop();
    int x = 0;
    if(c=='+')
        x=a+b;
    else if(c=='-')
        x=a-b;
    else if(c=='*')
        x=a*b;
    else if(c=='/')
        x=a/b;
    num.push(x);
}

int main()
{
    string s;
    unordered_map<char,int> priority_map{{'+',1},{'-',1},{'*',2},{'/',2}}; //定义操作符的优先级
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        char c = s[i];
        if(isdigit(c))
        {
            int j=i;
            int number = 0;
            while(j<s.size() && isdigit(s[j]))
                number = number * 10 + s[j++] - '0';
            i = j -1;
            num.push(number);
        }
        else if(c=='(')
        {
            op.push(c);
        }
        else if(c==')')
        {
            while(op.top()!='(')
            {
                eval();
            }
            op.pop();
        }
        else
        {
            while(op.size()&&priority_map[op.top()]>=priority_map[c]) eval();
            op.push(c);
        }
    }
    
    //栈内的剩余操作符的求值方法
    while(op.size()) eval();
    
    cout<< num.top()<<endl;
    return 0;
}