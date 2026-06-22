from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram = defaultdict(list)
        result = []

        for s in strs:
            sort_s = tuple(sorted(s))
            anagram[sort_s].append(s)
        
        for v in anagram.values():
            result.append(v)
        
        return result