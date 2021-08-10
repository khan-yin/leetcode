#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
            stack<int> stk;
            int n = popped.size();
            int m = pushed.size();
            int j = 0;
            for(int i=0;i<m;i++)
            {
                stk.push(pushed[i]);
                
                while(stk.size()&&stk.top()==popped[j])
                {
                    j++;
                    stk.pop();
                }
            }
            return stk.empty();
    }
};