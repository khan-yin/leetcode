#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

struct Range
{
    int l;
    int r;
    bool operator < (const Range & w) const
    {
        return l < w.l;
    }
}range[N];


int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &range[i].l, &range[i].r);
    }
    
    sort(range,range+n);
    int end = -2e9;
    int res = 0;
    //存储的是每个划分的最右边界        
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0;i<n;i++)
    {
        Range line = range[i];
        //说明当前最小的右边界划分与当前线段的左边界有交集，需要新开一个组
        if(q.empty() || q.top() >= line.l)  q.push(line.r);
        else
        {
            //更新划分的右边界
            q.pop();
            q.push(line.r);
        }
    }
    
    cout<<q.size()<<endl;
    return 0;
}