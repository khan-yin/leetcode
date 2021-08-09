// PAT甲级真题1097
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 100010;

int h, e[N],ne[N];
int n;
unordered_set<int> vis;

int main()
{
    scanf("%d%d",&h,&n);
    while (n -- )
    {
        int address,key,next;
        scanf("%d %d %d", &address, &key,&next);
        e[address] = key;
        ne[address] = next;
    }
    vector<int> res1,res2;
    for(int i = h;i!=-1;i=ne[i])
    {
        if(vis.count(abs(e[i])))
        {
            res2.push_back(i);
            continue;
        }
        vis.insert(abs(e[i]));
        res1.push_back(i);
    }

    for(int i=0;i<res1.size();i++)
    {
        printf("%05d %d ",res1[i],e[res1[i]]);
        if(i+1==res1.size()) puts("-1");
        else printf("%05d\n",res1[i+1]);
    }

    for(int i=0;i<res2.size();i++)
    {
        printf("%05d %d ",res2[i],e[res2[i]]);
        if(i+1==res2.size()) puts("-1");
        else printf("%05d\n",res2[i+1]);
    }
    return 0;
}
