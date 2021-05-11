#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 2*N;
int e[M], ne[M], head[N], idx;
int color[N];// -1表示未染色，0表示白色，1表示黑色



void add(int a,int b)
{
    e[idx] = b, ne[idx] = head[a], head[a] =idx++;
}


bool dfs(int id,int c)// 染色节点，颜色
{
    color[id]=c;
    for(int i = head[id];i!=-1;i=ne[i])
    {
        int node = e[i];
        if(color[node]==-1)//未被染色
        {
            if(!dfs(node,!c))//染色失败
            {
                return false;
            }
        }
        else if(color[node]==c) return false;
    }
    
    return true;
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    memset(head,-1,sizeof head);
    while(m--)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        add(a,b);
        add(b,a);
    }
    
    
    memset(color, -1,sizeof color);
    
    //对没有被染色的节点依次进行染色
    bool flag =true;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            if(!dfs(i,0))
            {
                flag=false;
                break;
            }
        }
    }
    
    cout<< (flag ? "Yes":"No") <<endl;

    return 0;
}