// PAT甲级真题1149
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int N = 10010;
const int M = 110;

int obj[N][2];



int n,m,k;

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &obj[i][0], &obj[i][1]);
    }

    while (m -- )
    {
        scanf("%d", &k);
        unordered_set<int> s;
        for(int i=0;i<k;i++)
        {
            int x;
            scanf("%d", &x);
            s.insert(x);
        }
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(s.count(obj[i][0]) && s.count(obj[i][1])) flag=false;
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}