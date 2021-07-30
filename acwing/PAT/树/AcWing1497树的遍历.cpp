// PAT甲级真题1020
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 40;

int postorder[N];
int inorder[N];
int q[N];

unordered_map<int,int> l,r,inorder_map; // 用map可以的原因是因为题中所给的节点权值各不相同

int n;



// 中序和后序的区间边界，返回值为根节点的坐标
int build(int il,int ir,int pl,int pr)
{
    int root = postorder[pr]; // 后续遍历的最后一个元素为根
    int k = inorder_map[root];// 找到根对应在中序当中的位置，划分区间继续递归构建左右子树
    if(k>il) l[root] = build(il,k-1,pl,pl+k-il-1);
    if(k<ir) r[root] = build(k+1,ir, pr-ir+k,pr-1);
    return root;
}



void bfs(int x)
{
    int head=0;
    int tail=0;
    q[0] = x;
    while(head<=tail)
    {
        int t = q[head++];
        if(l.count(t)) q[++tail] = l[t];
        if(r.count(t)) q[++tail] = r[t];
    }

    cout << q[0];
    for (int i = 1; i < n; i ++ ) cout << ' ' << q[i];
    cout << endl;
}


int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &postorder[i]);
    for(int i=0;i<n;i++) 
    {
        scanf("%d", &inorder[i]);
        inorder_map[inorder[i]]=i;
    }

    int root = build(0,n-1,0,n-1);
    bfs(root);
    return 0;
}
