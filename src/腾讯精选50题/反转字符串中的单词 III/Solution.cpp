#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int head=0;
        // string res="";
        int length=s.size();
        while(head<length)
        {
            int i=head;
            while(head<length&&s[head]!=' ') 
                head++;

            int left = i, right = head - 1;

            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            while (head < length && s[head] == ' ') {
                head++;
            }
        }
        return s;
    }
};