#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int A[N];
int B[N];

int main()
{
    int n,m,x;
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i ++ )
        scanf("%d", &A[i]);
    
    for (int i = 0; i < m; i ++ )
        scanf("%d", &B[i]);
    
    for (int i = 0, j = m - 1; i < n; i ++) {
        while(j >= 0 && A[i] + B[j] > x) j --;
        if(j >= 0 && A[i] + B[j] == x) 
            printf("%d %d\n", i, j);
    }
    
    return 0;
}

