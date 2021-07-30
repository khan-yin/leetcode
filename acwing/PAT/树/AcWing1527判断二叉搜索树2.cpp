// PAT甲级真题1043
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 1010;

int preorder[N],inorder[N],postorder[N];
int n, cnt;
int l[N],r[N];

// build构造树关系再通过dfs输出（由于权值可能相等，故使用索引构建树结构）
bool build(int il, int ir, int pl,int pr,int type)
{
    if(il>ir)
    {
        return true;
    }
    int root = preorder[pl]; //前序遍历第一个节点当前区间的根节点编号
    int k;
    if(type==0) //type为0表示未反转
    {
        // 可以用二分优化,但数据范围小没必要
        for(k = il;k<=ir;k++)
            if(inorder[k]==root) break;
        if(k>ir) return false; //说明在当前区间内没有找到该元素，无法继续构造树结构
    }
    else
    {
        // 可以用二分优化,但数据范围小没必要
        for(k = ir;k>=il;k--)
            if(inorder[k]==root) break;
        if(k<il) return false; //说明在当前区间内没有找到该元素，无法继续构造树结构
    }
    
    bool res=true;
    // if(pl==2 || pl ==3 || pl==5 || pl==6) cout<<pl<<" "<<il<<" "<<k-1<<" "<<pl+1<<" "<<pl+1+(k-1-il)<<endl;
    //遍历左子树
    if(!build(il,k-1,pl+1,pl+1+(k-1-il),type)) res=false;
    else if(il <= k-1 )l[pl] = pl+1;
    //遍历右子树
    if(!build(k+1,ir,pr - (ir - k -1),pr,type)) res=false;
    else if(k+1 <= ir) r[pl] = pr - (ir - k -1);
    // cout<<preorder[pl]<<" "<<preorder[l[pl]]<<" "<<preorder[r[pl]]<<endl;
    postorder[cnt++]=root;
    return res;
}


void dfs(int x)
{
    if(x==-1) return;
    if(l[x]) dfs(l[x]);
    if(r[x]) dfs(r[x]);
    if(x==0) cout<<preorder[0];
    else cout<<preorder[x]<<' ';
}

int main()
{
    scanf("%d", &n);
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &preorder[i]);
        inorder[i]= preorder[i];
        
    }
    sort(inorder,inorder+n);
    
    if(build(0,n-1,0,n-1,0))
    {
        puts("YES");
        // for(int i=0;i<n;i++) cout<<preorder[i]<<' '<<l[preorder[i]]<<" "<<r[preorder[i]]<<endl;
        dfs(0);
        // cout<<postorder[0];
        // for(int i=1;i<n;i++) cout<<' '<<postorder[i];  
        
    }
    else
    {
        reverse(inorder,inorder+n);
        cnt=0;
        if(build(0,n-1,0,n-1,1))
        {
            puts("YES");
            dfs(0);
            // dfs(postorder[0]);
            // cout<<postorder[0];
            // for(int i=1;i<n;i++) cout<<' '<<postorder[i];  
        }
        else
        {
            puts("NO");
        }
    }
    
    return 0;
}