#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100003; // 存储大于100000的第一个质数

int h[N], e[N], ne[N],idx;

void insert(int x)
{
    int k = (x % N + N) % N; // +N主要是为了防止余数为负
    // 单链表头插法
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k]; i!=-1; i = ne[i])
        if(e[i]== x)
            return true;
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(h,-1,sizeof(h)); // 初始化所有地址均为空链表
    while (n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I')
            insert(x);
        else
            cout<<( find(x) ? "Yes" : "No")<<endl;
    }   
    return 0;
}
