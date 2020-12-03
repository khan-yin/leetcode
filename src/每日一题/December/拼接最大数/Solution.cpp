#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    //求单调栈
    vector<int> GetMonStack(vector<int> &nums,int length){
        stack<int> s;
        int n=nums.size();
        int drop_num=n-length;
        for(int i=0;i<n;++i){
            while(!s.empty() && s.top()<nums[i] && drop_num>0){
                s.pop();
                --drop_num;
            }
            if(s.size()<length)s.push(nums[i]);
            else --drop_num;
        }
        return [](stack<int> ss){vector<int> res(ss.size(),0);int i=ss.size()-1;while(!ss.empty()){res[i--]=ss.top();ss.pop();}return res;}(s);
    }
    //合并两个vector
    vector<int> MergeVector(vector<int> &one,vector<int> &two){
        int size_one=one.size(),size_two=two.size();
        if(!size_one) return two;
        if(!size_two) return one;
        int a=0,b=0;
        int n=size_one+size_two,i=0;
        vector<int> res(size_one+size_two,0);
        while(i<n){
            if(compare(one,a,two,b)>0) res[i++]=one[a++];
            else res[i++]=two[b++];
        }
        return res;
    }
    //比较函数
    int compare(vector<int>& one, int index1, vector<int>& two, int index2) {
        int x = one.size(), y = two.size();
        while (index1 < x && index2 < y) {
            int tag = one[index1++] - two[index2++];
            if (tag != 0) return tag;
        }
        return (x - index1) - (y - index2);
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int size_num1=nums1.size(),size_num2=nums2.size();
        int start=max(0,k-size_num2),end=min(size_num1,k);
        vector<int> res(k,0);
        for(int i=start;i<=end;i++){
            vector<int> one(GetMonStack(nums1,i));
            vector<int> two(GetMonStack(nums2,k-i));
            vector<int> temp(MergeVector(one,two));
            if(compare(temp,0,res,0)>0) res.swap(temp);
        }
        return res;
    }
};
