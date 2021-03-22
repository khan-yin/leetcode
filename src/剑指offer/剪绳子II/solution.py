class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3: return n - 1
        a, y, p = n // 3, n % 3, 1000000007
        if y==0:
            return 3**a % p
        elif y==1:
            return 3**(a-1) *4 % p
        else:
            return 3**a *2 % p
