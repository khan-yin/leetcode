class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x^y;
        int cnt=0;
        while(t)
        {
            t -= t & -t;
            cnt++;
        }
        return cnt;
    }
};