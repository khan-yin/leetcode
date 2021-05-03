#include <iostream>
using namespace std;
const int N = 100010;

// e[i] 存储节点i的值
// l[i] 存储节点i的左边指针的坐标
// r[i] 存储节点i的右边指针的坐标
int e[N],l[N],r[N];
int idx; //记录已经使用了多少个节点


//初始化直接初始化出左右端点的下标，从而避免边界问题
void init()
{
    //初始化的左右别搞反了
    r[0] = 1;
    l[1] = 0;
    idx =2;
}

// 在k节点的右侧插入一个x
void add(int k,int x)
{
    e[idx] = x;
    //操作新节点的左右指针
    r[idx] = r[k];
    l[idx] = k;
    //再操作原数组的节点
    l[r[k]] = idx;
    r[k] = idx++;
}

void remove(int k)
{
    l[r[k]] = l[k]; //右节点的左侧，指向左节点
    r[l[k]] = r[k]; //左节点的右侧，指向右节点
}


int main()
{
    int m;
    scanf("%d", &m);
    
    init();
    
    while (m -- )
    {
        string op;
        cin>>op;
        int k,x;
        if(op=="R")
        {
            scanf("%d", &x);
            add(l[1],x);
        }
        else if(op=="L")
        {
            scanf("%d", &x);
            add(0,x);
        }
        else if(op=="D")
        {
            scanf("%d", &k);
            remove(k+1); // 因为idx=2 
        }
        else if(op=="IL")
        {
            scanf("%d%d", &k,&x);
            add(l[k+1],x);
        }
        else if(op=="IR")
        {
            scanf("%d%d", &k,&x);
            add(k+1,x);
        }
    }
    
    for(int i = r[0];i!=1; i = r[i]) printf("%d ",e[i]);
    
    return 0;
}