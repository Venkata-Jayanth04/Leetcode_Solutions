class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        dict = {}

        for word in strs:
            count = [0] * 26

            for char in word:
                index = ord(char) - ord('a')
                count[index] += 1

            key = tuple(count)

            if key in dict:
                dict[key].append(word)
            else:
                dict[key] = [word]
        
        return list(dict.values())