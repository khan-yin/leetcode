// PAT甲级真题1110
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


const int N = 30;
int n;
int l[N], r[N];
bool has_father[N];
int maxid=-1,maxk;


void dfs(int x,int k)
{
    if(x==-1) return;
    if(maxk < k)
    {
        maxk = k;
        maxid = x;
    }
    
    dfs(l[x],2*k);
    dfs(r[x],2*k+1);
    
}

/*

如果是完全二叉树，则输出 YES 以及最后一个结点(完全二叉树中的最后一个节点即最大的下标)的编号。

如果不是，则输出 NO 以及根结点的编号。
*/

int main()
{
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        if(a!="-")
        {
            l[i] = stoi(a);
            has_father[l[i]]=true;
        }
        if(b!="-")
        {
            r[i] = stoi(b);
            has_father[r[i]]=true;
        }
    }
    
    int root = 0;
    while(has_father[root]) root++;
    
    dfs(root,1);
    
    if(maxk==n) 
    {
        printf("YES %d\n",maxid);
    }
    else
    {
        printf("NO %d\n",root);
    }
    return 0;
}
