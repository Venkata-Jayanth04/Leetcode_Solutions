class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        target = 0
        count = 0
        costs.sort()
        n = len(costs)
        for i in range(n):
            target = target + costs[i]
            if target <= coins:
                count = count+1
                if count >= n:
                    return n
            else:
                return count
    