#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int m[1010];

class Solution {
public:
    int halfQuestions(vector<int>& questions) {
        int n = questions.size() / 2 ;
        memset(m,0, sizeof m);
        for(int i : questions)
        {
            m[i]++;
        }
        int c = 0;
        
        sort(m,m+1010);
        for(int i=1009;i>=0&&n>0;i--)
        {
            if(m[i]>0)
            {
                // cout<<i<<" "<<m[i]<<endl;
                n -= m[i];
                c ++;
            }
        }
        return c;
    }
};