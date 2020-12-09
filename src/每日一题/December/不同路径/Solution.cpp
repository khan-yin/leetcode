#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long total=m+n-2;
        long long fenzi=1;
        long long fenmu=1;
        int minn=min(m-1,n-1);
        for(int i=minn;i>0;i--)
        {
            fenzi*=total;
            fenmu*=i;
            total--;
        }
        // cout<<fenzi<<endl;
        // cout<<fenmu<<endl;
        return  (int)(fenzi/fenmu);
    }
};