class Solution:
    def isPalindrome(self, x: int) -> bool:
        k = x
        pal = 0
        for i in range(len(str(x))):
            n = x%10
            pal = pal*10 + n
            x = x//10
        
        return pal == k