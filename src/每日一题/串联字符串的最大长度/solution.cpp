#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int backtrace(vector<string>& arr, int i, int value)
    {
        if(i==arr.size()) return 0;
        int t = value;
        for(char c : arr[i])
        {
            //存在重复
            if( value & (1<<(c-'a')))
                return backtrace(arr,i+1,t);
            value |= (1<<(c-'a'));
        }
        int len = arr[i].length();
        return max(len+backtrace(arr,i+1,value),backtrace(arr,i+1,t));
    }
    int maxLength(vector<string>& arr) {
        return backtrace(arr,0,0);
    }
};