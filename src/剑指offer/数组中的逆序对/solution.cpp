#include<vector>
using namespace std;

class Solution {
public:
    // []left,right]区间,nums表示需要归并的数组，temp是nums的复制进行归并操作后将区间排序结果存入nums当中再继续递归下去
    int mergesort(int left,int right,vector<int>& nums,vector<int>& temp)
    {
        if(left>=right)//递归出口
            return 0;
        int mid = left+(right-left)/2;
        int res = mergesort(left,mid,nums,temp)+mergesort(mid+1,right,nums,temp);

        for(int i=left;i<=right;i++)
            temp[i]=nums[i];

        int i=left,j=mid+1;//左右区间

        for(int k=left;k<=right;k++)
        {
            if(i==mid+1)//左边区间归并完毕
            {
                nums[k]=temp[j++];
            }
            else if(j==right+1)//右边区间归并完毕
            {
                nums[k]=temp[i++];
            }
            else if(temp[i]<=temp[j])
            {
                nums[k]=temp[i++];
            }
            else if(temp[i]>temp[j])
            {
                nums[k]=temp[j++];
                res+=mid-i+1;
            }
        }
        return res;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergesort(0,nums.size()-1,nums,temp);
    }

};