// PAT甲级真题1027
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char get(int x)
{
    if (x <= 9) return '0' + x;
    return 'A' + x - 10;
}

int main()
{
    int a[3];
    for (int i = 0; i < 3; i ++ ) scanf("%d", &a[i]);
    
    cout<<"#";
    
    for (int i = 0; i < 3; i ++ ) cout<<get(a[i] / 13)<<get(a[i] % 13);
    return 0;
}