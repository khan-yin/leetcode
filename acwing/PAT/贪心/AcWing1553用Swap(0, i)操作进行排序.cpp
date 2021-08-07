// PAT甲级真题1067
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int p[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) 
    {
        int id;
        scanf("%d", &id);
        p[id]=i;
    }
    
    int res=0;
    for(int i=0;i<n;)
    {
        while(p[0]) swap(p[0],p[p[0]]), res++;
        while(p[i]==i) i++;
        if(i<n) swap(p[0],p[i]), res++;
    }
    cout<<res;
    return 0;
}