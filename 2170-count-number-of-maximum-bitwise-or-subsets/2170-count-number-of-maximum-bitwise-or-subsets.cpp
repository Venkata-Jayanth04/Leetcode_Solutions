class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, count = 0;
        
        for (int num : nums) {
            maxOr |= num;
        }
        
        int n = nums.size();
        
        for (int i = 1; i < (1 << n); ++i) {
            int currentOr = 0;
            
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    currentOr |= nums[j];
                }
            }
            
            if (currentOr == maxOr) {
                count++;
            }
        }
        
        return count;
    }
};