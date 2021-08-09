// PAT甲级真题1040
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;



int main()
{
    string str;
    getline(cin,str);
    int res = 0;
    for(int i=0;i<str.size();i++)
    {
        for(int j=str.size()-1;j>=i;j--)
        {
            int l = i, r = j;

            while(l<r&&str[l]==str[r])
            {
                l++;
                r--;
            }
            if(l>=r) 
            {
                res = max(res,j-i+1);
                break;
            }
        }
    }

    printf("%d\n",res);
    return 0;
}