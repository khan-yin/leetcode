// PAT甲级真题1049
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int calc(int x)
{
    vector<int> num;
    while(x) num.push_back(x%10), x/=10;
    int res = 0;

    for(int i=num.size()-1;i>=0;i--)
    {
        int d = num[i];
        int left=0,right=0,power=1;
        for(int j=num.size()-1;j>i;j--) left = left*10 + num[j];

        for(int j=i-1;j>=0;j--) 
        {
            right = right * 10 + num[j];
            power *=10;
        }

        if(d==0)
        {
            res +=left * power;
        }
        else if(d==1)
        {
            res += left * power + right + 1;
        }
        else
        {
            res += (left+1) * power;
        }

    }
    return res;
}


int main()
{
    scanf("%d", &n);
    printf("%d",calc(n));
    return 0;
}