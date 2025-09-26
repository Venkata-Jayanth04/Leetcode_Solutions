class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        long long total = 0;
        int left = 0;
        int maxfreq = 1;

        for(int right = 0; right < nums.size(); right++){
            total = total + nums[right];

            while((long long)(right - left + 1) * nums[right] - total > k){
                total = total - nums[left];
                left++;
            }

            maxfreq = max(maxfreq,right-left+1);
        }
            return maxfreq;
    }
};