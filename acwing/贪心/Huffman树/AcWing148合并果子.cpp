#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a;
        scanf("%d", &a);
        q.push(a);
    }
    int res = 0;
    while(q.size()>1)
    {
        int a =q.top(); q.pop();
        int b =q.top(); q.pop();
        res += (a+b);
        q.push(a+b);
    }
    cout<<res<<endl;
    return 0;
}