class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]

        for i in range(len(nums)-2):
            left,right = i + 1, len(nums) - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if abs(target - total) < abs(target - closest):
                    closest = total
                
                if total < target:
                    left=left + 1
                elif total > target:
                    right=right - 1
                else:
                    return total
        return closest