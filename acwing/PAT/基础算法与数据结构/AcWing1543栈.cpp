// PAT甲级真题1057
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>


using namespace std;

const int N = 100010;

int n;
stack<int> stk;

multiset<int> up,down; // 上面是用小根堆维护较大的部分，下面是用大根堆维护较小的部分
// 用两个平衡树当作堆来维护数据流的中位数
// 始终保持下面的比上面元素多1或者相等
int cnt=0;

void adjust()
{
    // up 比 down 元素多
    while(up.size() > down.size())
    {
        auto it = up.begin();
        down.insert(*it);
        up.erase(it);
    }
    
    // down 的数量比up多大于1
    while(down.size() > up.size() + 1)
    {
        auto it = down.end();
        it --;
        up.insert(*it);
        down.erase(it);
    }
}

int main()
{
    scanf("%d", &n);
    while (n -- )
    {
        string op;
        cin>>op;
        if(op=="Push")
        {
            int x;
            scanf("%d", &x);
            stk.push(x);
            if(up.empty() || x < *up.begin()) down.insert(x);
            else up.insert(x);
            
            adjust();
        }
        else if(op=="PeekMedian")
        {
            if(stk.empty()) puts("Invalid");
            else
            {
                auto it = down.end();
                it--;
                printf("%d\n",*it);
            }
        }
        else
        {
            if(stk.empty()) puts("Invalid");
            else
            {
                int t = stk.top();
                stk.pop();
                printf("%d\n",t);
                // multiset删除元素时，如果用multiset.erase(x)会删除所有x;
                //如果用multiset.erase(find(x))就只删除一个x
                
                // 这里删除时建议从down来判断，因为有可能up是空的
                auto it = down.end();
                it --;
                if(t<=*it) down.erase(down.find(t));
                else up.erase(up.find(t));
                adjust();
            }
            
        }
    }
    return 0;
}