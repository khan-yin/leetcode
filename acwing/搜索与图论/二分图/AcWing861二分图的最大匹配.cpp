#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 200010;
int head[N], e[M],ne[M],idx;
int match[N]; //match[j]=a,表示女孩j的现有配对男友是a
bool temp[N]; //temp[]数组我称为临时预定数组，temp[j]=a表示一轮模拟匹配中，女孩j被男孩a预定了。

void add(int a,int b)
{
    e[idx] =b, ne[idx] = head[a], head[a] = idx++;
}

bool find(int x)
{
    //遍历x喜欢的所有女孩
    for(int i = head[x];i!=-1;i=ne[i])
    {
        int girl = e[i];
        //如果该轮模拟中，当前女孩没有被预定，则预定该女孩
        if(!temp[girl])
        {
            temp[girl]=true;
            //如果当前女孩单身，或者当前女孩的现男友能预订他喜欢的下一个对象，则配对成功，更新配对方案
            if(!match[girl] || find(match[girl]))
            {
                match[girl] = x;
                return true;
            }
        }
    }
    return false;//该男生所有中意的女孩均无法满足所有男生的配对方案
}






int main()
{
    int n1,n2,m;
    scanf("%d%d%d", &n1,&n2, &m);
    
    memset(head,-1,sizeof head);
    while (m -- )
    {
        int a,b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    
    int res = 0;//总方案数
    //遍历每个男生的配对情况
    for(int i=1;i<=n1;i++)
    {
        //每次新一轮模拟时，需要将女孩临时预定情况情况
        memset(temp, false, sizeof temp);
        if(find(i)) res++;
    }
    cout<<res<<endl;
    return 0;
}