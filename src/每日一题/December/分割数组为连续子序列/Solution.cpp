#include<unordered_map>
#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> numsCntMap;//numsCntMap[num]表示的是num剩余的个数
        unordered_map<int, int> numsEndCntMap;//numsEndCntMap[num]表示的时以num结尾的连续子序列（长度不小于3）个数
        //统计各个元素出现的次数
        for (auto num : nums){
            numsCntMap[num] += 1;
        }

        for(auto num:nums)
        {
            if(numsCntMap[num]==0)
                continue;
            //使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。注意，map中不存在相同元素，所以返回值只能是1或0。使用find，返回的是被查找元素的位置，没有则返回map.end()
            numsCntMap[num]-=1;//当前num执行-1
            
            if(numsCntMap.count(num-1)&&numsEndCntMap[num-1]>0)
            {
                //存在以num - 1结尾的连续子序列（长度不小于3），则将num放入
                numsEndCntMap[num-1]-=1;//以num - 1结尾的连续子序列（长度不小于3）自减，因为被num放入使用了一个
                numsEndCntMap[num] += 1;//以num结尾的连续子序列（长度不小于3）自增，刚刚创建了一个
            }
            else if(numsCntMap.count(num+1)&&numsCntMap.count(num+2)&&numsCntMap[num+1]>0&&numsCntMap[num+2]>0)
            {
                numsCntMap[num+1]-=1;
                numsCntMap[num+2]-=1;
                numsEndCntMap[num+2]+=1;
            }
            else
                return false;
        }

        return true;
    }
};


