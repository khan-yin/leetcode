#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

double dist[205];

struct Node
{
    int i;
    double dis;
};

inline double getdistance(int x1,int y1,int x2,int y2)
{
    return (double)((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}

Node nodelist[205];

bool cmp(Node a,Node b)
{
    if(a.dis==b.dis)
    {
        return a.i<b.i;
    }
    else
    {
        return a.dis<b.dis;
    }
    
}
int main()
{
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    for(int i=1;i<=n;i++)
    {
        int xx,yy;
        scanf("%d %d",&xx,&yy);
        nodelist[i].i=i;
        nodelist[i].dis=getdistance(x,y,xx,yy);
    }

    sort(nodelist+1,nodelist+n+1,cmp);

    printf("%d\n",nodelist[1].i);
    printf("%d\n",nodelist[2].i);
    printf("%d\n",nodelist[3].i);
    return 0;
}