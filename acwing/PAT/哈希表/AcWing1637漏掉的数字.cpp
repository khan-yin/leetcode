// PAT甲级真题1144
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;


const int N = 100010;

unordered_set<int> S;

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int x;
        cin>>x;
        if(x>0) S.insert(x);
    }
    
    int res = 1;
    while(S.count(res)) res++;
    cout<<res<<endl;
    return 0;
}