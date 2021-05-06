#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f; 
// 存储大于2*100000的第一个质数扩大了一倍的空间保证一定有解，null是一个大于10^9次方的数

int h[N];

int find(int x) // 如果x存在，返回存储的地址，如果不存在则返回应该存储的位置
{
    int k = (x % N + N) % N;
    while(h[k]!=null && h[k]!=x) // 地址上有元素且不是x
    {
        k++;
        if(k==N) k=0;
    }
    return k;
}



int main()
{
    int n;
    scanf("%d", &n);
    memset(h,0x3f,sizeof(h));
    
    for (int i = 0; i < n; i ++ )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if(*op == 'I')
            h[k]=x;
        else
            cout<< (h[k]==x? "Yes" : "No")<<endl;
    }
    return 0;
}