#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

//利用优先队列执行哈弗曼树操作
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int apple;
        cin>>apple;
        q.push(apple);
    }
    int res = 0;
    while(q.size()>1)
    {
        int a,b;
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        res += (a+b);
        q.push(a+b);
    }
    cout<<res<<endl;
    return 0;
}