#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int top=-1;
int stk[N];

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        string op;
        cin>>op;
        if(op=="push")
        {
            int x;
            scanf("%d", &x);
            stk[++top]=x;
        }
        else if (op=="query")
        {
            cout<<stk[top]<<endl;
        }
        else if(op=="pop")
        {
            top--;
        }
        else if(op=="empty")
        {
            cout<< (top==-1? "YES":"NO") <<endl;
        }
    }
    return 0;
}