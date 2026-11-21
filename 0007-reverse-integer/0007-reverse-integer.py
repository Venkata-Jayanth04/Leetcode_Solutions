class Solution:
    def reverse(self, x: int) -> int:
        t = 0
        sign = -1 if x < 0  else 1
        x = abs(x)

        while x!=0:
            r = x%10
            t = t*10 + r
            x = x//10
        
        fin = sign*t

        if fin < -2**31 or fin > 2**31 - 1:
            return 0
        
        return fin