class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if not nums:
            return 0

        list1 = sorted(nums)
        count = 1
        max_count = 1

        for i in range(len(nums) - 1):
            if list1[i+1] == list1[i]:
                continue
            elif list1[i+1] - list1[i] == 1:
                count = count + 1
            else:
                max_count = max(max_count, count)
                count = 1
            
        return max(max_count,count)