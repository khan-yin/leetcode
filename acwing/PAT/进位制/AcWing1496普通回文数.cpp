// PAT甲级真题1019
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> num10_b(int n,int b)
{
    vector<int> res;
    if(!n) res.push_back(0);
    while(n)
    {
        res.push_back(n % b);
        n /=b;
    }
    return res;
}


bool check(vector<int> &num)
{
    for(int i = 0, j = num.size() - 1; i<j;i++,j--)
    {
        if(num[i]!=num[j]) return false;
    }
    return true;
}

int main()
{
    int n,b;
    cin>>n>>b;
    vector<int> num = num10_b(n,b);
    if(check(num)) puts("Yes");
    else puts("No");
    int len = num.size() - 1;
    cout<<num[len];
    for(int i=len-1; i>=0; i--) cout<<' '<<num[i];
    return 0;
}