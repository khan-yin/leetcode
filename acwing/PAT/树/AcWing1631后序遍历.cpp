// PAT甲级真题1138
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 50010;
int n;
unordered_map<int,int> l,r,pos;
int pre[N],in[N];
int cnt=-1;

int build(int il,int ir,int pl,int pr)
{
    int root = pre[pl];
    int k = pos[root];
    if(k>il) build(il,k-1,pl+1,pl+1+k-1-il);
    if(k<ir) build(k+1,ir,pl+1+k-il,pr);
    if(cnt==-1) cnt=root;
    return root;
}

int main()
{
    scanf("%d", &n);
    for(int i =0;i<n;i++) scanf("%d", &pre[i]);
    for(int i =0;i<n;i++)
    {
        scanf("%d", &in[i]);
        pos[in[i]]=i;
    }
    
    build(0,n-1,0,n-1);
    
    cout<<cnt<<endl;
    return 0;
}