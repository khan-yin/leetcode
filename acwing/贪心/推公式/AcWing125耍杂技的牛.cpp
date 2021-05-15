#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 50010;


PII p[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++ )
    {
        int w,s;
        scanf("%d%d", &w, &s);
        p[i].first = w +s;
        p[i].second = s;
    }
    
    sort(p,p+n);
    
    int totalw=0;
    int res = -2e9 + 10;
    
    for(int i=0;i<n;i++)
    {
        int x = p[i].first;
        int y = p[i].second;
        res = max(res,totalw - y);
        totalw+=x-y;
    }
    
    cout<<res<<endl;
    return 0;
}