#include<string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n==0) return 0;
        long long start=1;//起始
        long long digit=1;//数位
        long long count=start*digit*9;//个数
        while(n>count)
        {
            n-=count;
            start*=10;
            digit++;
            count=start*digit*9;
        }
        
        long long num = start+(n-1)/digit;
        int index = (n-1)%digit;
        string str = to_string(num);
        return str[index]-'0';
    }
};