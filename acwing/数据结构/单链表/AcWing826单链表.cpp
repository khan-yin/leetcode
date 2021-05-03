#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

// 静态链表实现

int head; // 头节点的下标
int idx; //记录已经存储了多少个节点

int element[N], ne[N]; // element[i]表示节点i的值 ne[i]表示节点i的next指针指向的下标


void init()
{
    head = -1;
    idx = 0;
}

// 单链表在头节点处插入元素
void insert_into_head(int x)
{
    element[idx] = x;
    ne[idx] = head; // 新节点指向head的next
    head = idx++; // head的next指向新节点
}

// 在第k个节点后面插入一个节点
void insert(int k,int x)
{
    element[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

// 删除第k个结点后面
void remove(int k)
{
    ne[k] = ne[ne[k]]; // k -> ne[k] -> ne[ne[k]] ==> k -> ne[ne[k]]
}

// 删除头节点，即head指向head->next
void remove_head()
{
    head = ne[head];
}

int main()
{
    int m;
    scanf("%d", &m);
    
    //忘记了init导致一直TLE T_T
    init();
    
    while (m -- )
    {
        // cout<<m<<endl;
        char op;
        int k, x;
        cin>>op;
        // cout<<op<<endl;
        if(op == 'H')
        {
            scanf("%d", &x);
            // cout<<op<<" "<<x<<" "<<endl;
            insert_into_head(x);
        }
        else if(op == 'D')
        {
            // 删除第 k 个插入的数（下标为k-1的点）后面的数 
            scanf("%d", &k);
            // cout<<op<<" "<<k<<" "<<endl;
            if(k==0) 
                remove_head(); // k为0表示删除头节点
            else
                remove(k-1);
        }
        else if(op == 'I')
        {
            // 在第 k 个插入（下标为k-1的点）的数后插入一个数
            scanf("%d%d",&k,&x);
            // cout<<op<<" "<<k<<" "<<x<<endl;
            insert(k-1,x);
        }

    }
    
    for (int i = head; i!=-1; i = ne[i] ) printf("%d ",element[i]);
    return 0;
}