#include <iostream>


using namespace std;

const int N = 100010;

int heap[N],heapsize=0;

void down(int x)// 参数下标
{
    int p =x;
    if(2*x<=heapsize && heap[2*x]<heap[p]) p = 2*x;//左子树
    
    if(2*x+1<=heapsize && heap[2*x+1]<heap[p]) p=2*x+1;//右子树
    
    if(p!=x) 
    {
        swap(heap[p],heap[x]); //说明存在比父节点小的孩子节点
        down(p); //继续向下递归down
    }
}


void up(int x)// 参数下标
{
    while(x / 2 && heap[x] < heap[x/2]) //父节点比子节点大则交换
    {
        swap(heap[x],heap[x/2]);
        x >>= 1; // x = x/2
    }
}

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &heap[i]);
    heapsize=n;
    
    // O(n)建堆
    for (int i = n / 2; i; i -- ) down(i);
    
    while (m -- )
    {
        printf("%d ",heap[1]); //最小值是小根堆的堆顶
        // 删除最小值，并重新建堆排序，从而获得倒数第二小的元素
        heap[1] = heap[heapsize];
        heapsize--;
        down(1);
    }
    return 0;
}