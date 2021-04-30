#include <iostream>

using namespace std;

const int N = 100010;

int a[N];

int c[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int res=0;
    for (int i = 0,j = 0; j < n; j ++ )
    {
        c[a[j]]++;
        while(c[a[j]]>1)//出现重复的字符，当前不重复子序列的长度就确定了，移动i指针并消除之前的字符记录
        {
            c[a[i]] --;
            i++;
        }
        
        //在没有重复字符时每次都会更新长度
        res = max(res,j-i+1);
    }
    printf("%d",res);
    return 0;
}