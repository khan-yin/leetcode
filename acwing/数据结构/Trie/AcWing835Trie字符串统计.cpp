#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int son[N][26]; //记录节点和他的分支
int idx; //表示已经存储了多少个节点
int cnt[N]; // 以该节点结尾的字符串个数

char s[N]; //字符串


void insert(char* str)
{
    int p = 0; // 从根节点下标开始
    for(int i=0; str[i]; i++)
    {
        int value = str[i] - 'a';
        if(!son[p][value])  son[p][value]= ++idx; //该节点不存在则创建节点
        p = son[p][value];  // 指向该节点继续向下遍历
    }
    cnt[p]++; //对于该尾节点为结尾的字符串数量++
}


int query(char* str)
{
    int p = 0;
    for(int i=0;str[i];i++)
    {
        int value = str[i] - 'a';
        if(!son[p][value])  return 0; //节点不存在
        p = son[p][value];  
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        char op[2]; // 使用字符数组主要是因为直接读入char会读入空格等不必要信息。
        scanf("%s%s", op,s);
        if(op[0]=='I')
        {
            insert(s);
        }
        else
        {
            printf("%d\n",query(s));
        }
    }
    return 0;
}
