#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left=0;
        int right=numbers.size()-1;
        while(left<right)
        {
            int mid = left + (right - left)/2;
            if(numbers[mid]>numbers[right])
                left = mid +1;
            else if(numbers[mid]<numbers[right])
                right = mid;
            else if (numbers[mid]==numbers[right])
                right--;

        }
        return numbers[left];
    }
};