#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int res=0;
        int yp=0;
        for(int year = 1900;year<=2000;year++)
        {
            int p=0;
            for(int i=0;i<birth.size();i++)
            {
                if(year>=birth[i]&&year<=death[i]) p++;
            }
            if(p>yp)
            {
                yp= p;
                res = year;
            }
        }
        return res;
    }
};