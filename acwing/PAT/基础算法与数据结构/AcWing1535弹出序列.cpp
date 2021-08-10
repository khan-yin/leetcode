// PAT甲级真题1051
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 1010;
int a[N];

// 第一行包含三个整数 M,N,K，分别表示栈的容量，数字个数，需要判断的序列个数。
// 接下来 K 行，每行包含一个 1∼N 的排列。

int m,n,k;

bool check()
{
    stack<int> stk;
    int j = 1;
    for(int i=1;i<=n;i++)
    {
        stk.push(i);
        // 超出容量
        if(stk.size()>m) return false;

        while(stk.size()&&stk.top()==a[j]) // 栈顶等于当前序列元素则pop
        {
            stk.pop();
            j++;
        }

    }

    return stk.empty();
}

int main()
{
    scanf("%d%d%d", &m, &n, &k);

    while (k -- )
    {
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        if(check()) puts("YES");
        else puts("NO");
    }

    return 0;
}
