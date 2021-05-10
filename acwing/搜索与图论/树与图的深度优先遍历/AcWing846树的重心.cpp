#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

const int N = 100010;
const int M = 2 * N; //以有向图的格式存储无向图，所以每个节点至多对应2n-2条边
//邻接表存储
int head[N],e[M],ne[M],idx;//idx存储的是边的个数
int n;
bool isvisited[N];
int ans=N;

void add(int a, int b)
{
    e[idx]=b;
    ne[idx] = head[a];
    head[a] = idx++;
}


int dfs(int x)//节点编号
{
    int res = 0; // 记录去除当前节点后剩余联通块的节点数
    int size = 1; //以该节点为根节点构成的子树的点数
    isvisited[x]=true;
    
    for(int i = head[x];i!=-1;i=ne[i]) //链表遍历：i=ne[i]
    {
        int id = e[i];
        if(!isvisited[id])
        {
            int s = dfs(id);
            size +=s;
            res = max(res,s);
        }
    }
    res = max(res,n-size);
    ans = min(ans,res);
    return size;
}



int main()
{
    memset(head, -1, sizeof head); //初始化h数组 -1表示尾节点
    cin >> n; //表示树的结点数

    // 题目接下来会输入，n-1行数据，
    // 树中是不存在环的，对于有n个节点的树，必定是n-1条边
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        add(a, b), add(b, a); //无向图
    }

    dfs(1); //可以任意选定一个节点开始 u<=n

    cout << ans << endl;

    return 0;
}
