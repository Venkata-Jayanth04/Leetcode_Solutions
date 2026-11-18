class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1 = {}
        dict2 = {}
        if len(s) == len(t):
            for i in range(len(s)):
                if s[i] in dict1:
                    dict1[s[i]] = dict1[s[i]] + 1
                else:
                    dict1[s[i]] = 1
            
            for i in range(len(t)):
                if t[i] in dict2:
                    dict2[t[i]] = dict2[t[i]] + 1
                else:
                    dict2[t[i]] = 1
        else:
            return False
        return dict1 == dict2