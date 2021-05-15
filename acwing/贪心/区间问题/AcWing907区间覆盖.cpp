#include <iostream>
#include <cstring>
#include <algorithm>

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
    int s,t;
    scanf("%d%d", &s, &t);
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &range[i].l, &range[i].r);
    }
    //按左端点排序
    sort(range,range+n);
    int start = s;
    int res = 0;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        //选择小于start的当中，右端点最大的一个区间
        int j = i;
        int r = -2e9;
        while(j<n&&range[j].l <= start)
        {
            r = max(r,range[j].r);
            j++;
        }
        //最大的右端点r比start小，则无交集 或者 r=-2e9即所有区间都比start大 说明查找失败
        if(start > r)
        {
            break;
        }
        
        res++;
        //如果r以及大于线段右端点t了则无需再遍历
        if(r >= t)
        {
            flag=true;
            break;
        }
        
        i = j-1;
        start = r;
    }
    if(!flag) res = -1;
    cout<<res<<endl;
    return 0;
}