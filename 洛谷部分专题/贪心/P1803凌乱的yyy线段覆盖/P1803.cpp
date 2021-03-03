#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;

struct Line
{
    int start;
    int end;
    int len;
};

Line line[1000006];

//贪心策略应该看右端点的位置而不是左端点
bool cmp(Line a,Line b)
{
    if(a.end==b.end)
    {
        return a.len<=b.len;
    }
    return a.end<b.end;
}


bool isvisited[10000006];


int main()
{
    cin>>n;
    int maxend=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&line[i].start,&line[i].end);
        maxend = max(maxend,line[i].end);
        line[i].len = line[i].end - line[i].start;
    }

    sort(line+1,line+n+1,cmp);
    int firstend = line[1].end;//取第一条line
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        int start = line[i].start;
        if(start>=firstend)
        {
            cnt++;
            firstend=line[i].end;
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}