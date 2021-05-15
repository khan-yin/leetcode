#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Range
{
    int x;
    int y;
    bool operator < (const Range & w) const
    {
        return y < w.y;
    }
}range[N];


int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &range[i].x, &range[i].y);
    }
    
    sort(range,range+n);
    int end = -2e9;
    int res = 0;
    
    for(int i=0;i<n;i++)
    {
        if(range[i].x > end)
        {
            end = range[i].y;
            res++;
        }
    }
    
    cout<<res<<endl;
    return 0;
}