#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(auto i : nums)
            map[i]++;
        vector<vector<int>> res;
        for(auto item : map)
        {
            int num1 = item.first;
            int num2 = target - num1;;
            if(item.second > 0 && map.find(num2)!=map.end())
            {
                // 计算对数，考虑相等情况
                int cnt = 0;
                if (num1 != num2)
                {
                    cnt = min(item.second, map[num2]);
                    // 擦完后需要把num1和num2的对应数量直接置为0，因为后续没有数字可以再匹配
                    map[num1] = 0;
                    map[num2] = 0;
                }
                else
                {
                    // 相等取一半
                    cnt = item.second/2;
                    // 擦完后需要把num1和num2的对应数量直接置为0，因为后续没有数字可以再匹配
                    map[num1] = 0;
                }
                
                // 插入cnt的对数
                for (int i = 0; i < cnt; ++i)
                {
                    res.push_back({num1, num2});
                }
            }
        }
        return res;
    }
};