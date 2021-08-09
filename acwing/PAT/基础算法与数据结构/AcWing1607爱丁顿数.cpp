// PAT甲级真题1117
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000100;

int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    sort(a+1,a+n+1);
    int h_index=n;
    while(h_index>0&&a[n+1-h_index]<=h_index)
    {
        h_index--;
    }
    cout<<h_index;
    return 0;
}
