#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
    stack<char>  ls;
    long a,b;
    cin>>a>>b;
    long res=a+b;
    if(res<0)
    {
        printf("-");
        res=res*(-1);
    }
    int doh=0;
    while(res>=10)
    {
        int one=res%10;
        res=res/10;
        ls.push((one+'0'));
        if((ls.size()-doh)%3==0)
        {
            ls.push(',');
            doh++;
        }
    }
    ls.push((res+'0'));
    int k=1;
    while (!ls.empty())
    {
        cout << ls.top();
        ls.pop();
        k++;
    }
    return 0;
}