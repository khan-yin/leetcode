#include <iostream>
#include <cstring>
#include <algorithm>
typedef unsigned long long ULL;
using namespace std;
//核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
//小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果

const int N = 100010;

const int P = 131; // p进制经验值

ULL h[N],p[N];// h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64
char str[N];



// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    int n,m;
    scanf("%d%d%s", &n, &m,str+1);
    
    p[0]=1;
    for (int i = 1; i <= n; i ++ )
    {
        h[i] = h[i-1] * P + str[i];
        p[i] = p[i-1] * P;
    }
    
    
    while (m -- )
    {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        
        cout<< (get(l1,r1) == get(l2,r2) ? "Yes" : "No") <<endl;
        
    }
    return 0;
}
