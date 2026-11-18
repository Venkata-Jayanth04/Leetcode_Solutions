class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict = {}
        if len(s) != len(t):
            return False
    
        for i in range(len(s)):
            if s[i] in dict:
                dict[s[i]] = dict[s[i]] + 1
            else:
                dict[s[i]] = 1
            
        for i in range(len(t)):
            if t[i] in dict:
                dict[t[i]] = dict[t[i]] - 1
            else:
                return False
        
        for value in dict.values():
            if value!=0:
                return False
        
        return True