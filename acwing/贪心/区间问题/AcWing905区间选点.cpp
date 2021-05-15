#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range
{
    int l;
    int r;
    bool operator < (const Range & w) const
    {
        return r < w.r;
    }
}range[N];


int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &range[i].l, &range[i].r);
    }
    
    sort(range,range+n);
    int end = -2e9;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        if(end<range[i].l)
        {
            end = range[i].r;
            res++;
        }
    }
    
    cout<<res<<endl;
    return 0;
}