#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int i =0;
        int n =s.size();
        for(i=0;i<n;i+=2*k)
        {
            reverse(s.begin()+i,s.begin()+min(i+k,n));
        }
        return s;
    }
};