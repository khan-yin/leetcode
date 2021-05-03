#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N];
int stk[N];
int top=0;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
        scanf("%d", &a[i]);
    
    for (int i = 0; i < n; i ++ )
    {
        while(top&&stk[top]>=a[i]) top--;
        if(top<=0) 
        {
            cout<<"-1 ";
        }
        else
            cout<<stk[top]<<" ";
        stk[++top]=a[i];
    }
    
    return 0;
}