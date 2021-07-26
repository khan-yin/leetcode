#include <iostream>
#include <cstring>
#include<string>
#include <algorithm>

using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int c = a+b;
    string nums = to_string(c);
    string res;
    for(int i = nums.size() -1, j = 0;i>=0;i--)
    {
        res = nums[i] + res;
        j++;
        if(j % 3 == 0 && i && nums[i-1]!='-') res = ',' + res;
    }
    cout<<res<<endl;
    return 0;
}