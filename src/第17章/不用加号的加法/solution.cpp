class Solution {
public:
    int add(int a, int b) {
        while(b!=0)
        {
            int c = (unsigned int)(a&b)<<1;
            a^=b;
            b=c;
        }
        return a;
    }
};