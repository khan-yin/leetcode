#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int top=-1;
int q[N];
int head = 0;
int tail = -1;

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
            q[++tail]=x;

        }
        else if (op=="query")
        {
            cout<<q[head]<<endl;
        }
        else if(op=="pop")
        {
            head++;
        }
        else if(op=="empty")
        {
            cout<< (head>tail? "YES":"NO") <<endl;
        }
    }
    return 0;
}