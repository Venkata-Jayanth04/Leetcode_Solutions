class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        loop = {}

        for i in range(len(nums)):
          if nums[i] in loop:
            return True
          else:
            loop[nums[i]] = 1
        
        return False