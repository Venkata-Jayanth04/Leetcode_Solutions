class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        str_freq = {}
        tar_freq = {}

        for ch in s:
            str_freq[ch] = str_freq.get(ch,0) + 1
        
        for ch in target:
            tar_freq[ch] = tar_freq.get(ch,0) + 1
        
        ans = float('inf')

        for ch in tar_freq:
            ans = min(ans, str_freq.get(ch,0)//tar_freq[ch])
        
        return ans