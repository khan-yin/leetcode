// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while(l<r)
        {
            // long tmp = (long)l + r >> 1;
            // int mid = (int)tmp;
            int mid = l + (r - l >> 1); // 防止计算时溢出
            //版本出错
            if(isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};