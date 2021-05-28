#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int map[26];
    vector<int> masterMind(string solution, string guess) {
        vector<int> res(2);
        for(int i=0;i<4;i++)
            map[solution[i]-'A']++;
        int total=0;
        for(int i=0;i<4;i++)
        {
            if(solution[i]==guess[i]) res[0]++;
            if(map[guess[i]-'A']>0)
            {
                map[guess[i]-'A']--;
                total++;
            }
        }
        res[1] = total - res[0];
        return res;
    }
};