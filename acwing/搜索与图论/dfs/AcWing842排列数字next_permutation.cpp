#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
int n;

int a[N];

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        a[i] = i+1;
        printf("%d ", i+1);
    }
    printf("\n");
    while(next_permutation(a,a+n))
    {
        for(int i=0;i<n;i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}