// PAT甲级真题1032
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int h1,h2,e[N],ne[N],idx;
bool vis[N];


int main()
{
    int n;
    scanf("%d%d%d",&h1,&h2,&n);
    
    while (n -- )
    {
        int address,next;
        char data;
        scanf("%d %c %d", &address,&data,&next);
        e[address] = data;
        ne[address] = next;
    }
    
    for(int i=h1;i!=-1;i=ne[i])
        vis[i]=true;
    
    for(int i=h2;i!=-1;i=ne[i])
    {
        if(vis[i]) 
        {
            printf("%05d\n",i);
            return 0;
        }
    }
    
    puts("-1");
    
    return 0;
}