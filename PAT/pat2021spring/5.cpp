#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

bool isvisited[205];
int dist[205];
int truckmap[205][205];

vector<int> myroute;

struct Edge
{
    int to;
    int dis;
};

vector<Edge>  tmap[205];
bool cmp(Edge a,Edge b)
{
    return a.dis<b.dis;
}

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
    dist[0]=0;
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
        tmap[start].push_back((Edge){end,dis});
        tmap[end].push_back((Edge){start,dis});
    }

    myroute.push_back(0);
    isvisited[0]=true;

    for(int i=0;i<=n;i++)
    {
        sort(tmap[i].begin(),tmap[i].end(),cmp);
    }
    long long res = 0;
    while(myroute.size()<=n)
    {
        int len=myroute.size();
        int minnode = -1;
        int mindis = 2000;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<tmap[i].size();j++)
            {
                int node = tmap[i][0].to;
                int tdis = tmap[i][0].dis;
                if(!isvisited[node]&&mindis>tdis)
                {
                    mindis=tdis;
                    minnode=node;
                }
            }
        }
        if(mindis==-1)
            break;
        res +=mindis;
        cout<<"node"<<minnode<<endl;
        dist[minnode]= mindis;
        isvisited[minnode]=true;
        myroute.push_back(minnode);
        for(int i = 0; i<tmap[minnode].size();i++)
        {
            int node = tmap[minnode][i].to;
            int tdis = tmap[minnode][i].dis;
            if(dist[node]>dist[minnode]+tdis)
            {
                dist[node]=dist[minnode]+tdis;
            }
        }
    }
    for(int i=0;i<myroute.size();i++)
    {
        cout<<myroute[i]<<" ";
    }
    cout<<endl;
    cout<<res<<endl;
    return 0;
}