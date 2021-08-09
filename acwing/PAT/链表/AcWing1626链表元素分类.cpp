// PAT甲级真题1133
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;
int n,k;
int h,e[N],ne[N];


int main()
{
    scanf("%d%d%d",&h, &n, &k);

    while (n -- )
    {
        int address,key,next;
        scanf("%d%d%d", &address, &key,&next);
        e[address] = key;
        ne[address] = next;
    }

    vector<int> a,b,c;

    for(int i = h;i!=-1;i=ne[i])
    {
        if(e[i]<0) a.push_back(i);
        else if(e[i]<=k) b.push_back(i);
        else c.push_back(i);
    }

    a.insert(a.end(),b.begin(),b.end());
    a.insert(a.end(),c.begin(),c.end());

    for(int i=0;i<a.size();i++)
    {
        printf("%05d %d ",a[i],e[a[i]]);
        if(i+1==a.size()) puts("-1");
        else printf("%05d\n",a[i+1]);
    }


    return 0;
}