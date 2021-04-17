class Solution {
public:
    int add(int a, int b) {
        // 后续用a表示非进位和，b表示进位，当进位为0，则表示计算结束
        return b == 0 ? a : add(a^b, (unsigned int)(a&b) << 1);
    }
};
