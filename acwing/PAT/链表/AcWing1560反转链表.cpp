// PAT甲级真题1074
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
    scanf("%d%d%d",&h,&n,&k);
    while (n -- )
    {
        int address,next;
        int data;
        scanf("%d %d %d", &address,&data,&next);
        e[address] = data;
        ne[address] = next;
    }
    vector<int> res;

    for(int i=h;i!=-1;i=ne[i])
    {
        // printf("%05d %d %05d\n",i,e[i],ne[i]);
        res.push_back(i);
    }
    
    for(int i=0;i+k-1<res.size();i+=k)
    {
         reverse(res.begin()+i,res.begin()+i+k);
    }
    
    for(int i=0;i<res.size();i++)
    {
        printf("%05d %d ",res[i],e[res[i]]);
        if(i+1==res.size()) puts("-1");
        else printf("%05d\n",res[i+1]);
    }
    
    
    return 0;
}