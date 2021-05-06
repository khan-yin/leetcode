#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int p[N];

int find(int x) // 查找x的祖先节点，并在回溯的过程当中进行路径压缩，将各节点直接指向根节点
{
    if(x!=p[x]) p[x] = find(p[x]); // x和p[x]不相等，则继续向上找父节点的父节点
    return p[x];
}


int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    
    //首先每个节点以自己为根节点
    for (int i = 1; i <= n; i ++ )
        p[i] = i;
    
    while (m -- )
    {
        char op[2];
        int a,b;
        scanf("%s%d%d", op, &a,&b);
        if(op[0]=='M')
        {
            p[find(b)] = find(a); 
        }
        else
        {
            cout<< (find(b)==find(a) ? "Yes" : "No")<<endl;
        }
    }

    return 0;
}