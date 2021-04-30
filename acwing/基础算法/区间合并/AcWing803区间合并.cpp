#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

struct Range
{
    int start;
    int end;
};


bool cmp(Range &a, Range &b)
{
    return a.start <= b.start;
}

Range a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
        scanf("%d%d", &a[i].start,&a[i].end);
    
    //按左端点排序，判断区间相交情况，贪心求解    
    sort(a,a+n,cmp);
    
    int cnt=1;
    int lasted=a[0].end;
    for(int i=1;i<n;i++)
    {
        if(a[i].start<=lasted)
        {
            lasted=a[i].end>lasted?a[i].end:lasted;
        }
        else
        {
            lasted=a[i].end;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}