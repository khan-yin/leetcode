#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<vector>

using namespace std;

bool isvisited[205];
int dist[205];
int truckmap[205][205];

vector<int> myroute;



int main()
{
    int n,m;
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j)
                truckmap[i][j]=0;
            else 
                truckmap[i][j]=2000;
        }
    }

    for(int i=1;i<=n;i++)
    {
        dist[i]=truckmap[0][i];
    }

    for(int i=1;i<=m;i++)
    {
        int start,end,dis;
        scanf("%d %d %d",&start,&end,&dis);
        truckmap[start][end]=dis;
        truckmap[end][start]=dis;
    }

    myroute.push_back(0);
    isvisited[0]=true;

    for(int j=1;j<=n;j++)
    {
        if(isvisited[j])
            continue;
        int len=myroute.size();
        bool flag=false;
        for(int k=0;k<len;k++)
        {
            int node=myroute[k];
            if(dist[j]>dist[node]+truckmap[node][j])
            {
                dist[j]=dist[node]+truckmap[node][j];
                isvisited[j]=true;
                // myroute.push_back(j);
                flag=true;
            }
        }
        if(flag)
            myroute.push_back(j);
    }

    return 0;
}