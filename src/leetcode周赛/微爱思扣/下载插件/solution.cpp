class Solution {
public:
    int leastMinutes(int n) {
        int k = 1;
        int c = 1;
        while(k<n)
        {
            k*=2;
            c++;
        }
        return c;
    }
};