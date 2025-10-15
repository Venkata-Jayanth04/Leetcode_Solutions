class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                inc[i] = inc[i + 1] + 1;
            }
        }

        int left = 1, right = n / 2;
        int res = 0;

        auto canFind = [&](int k) {
            for (int i = 0; i + 2 * k <= n; i++) {
                if (inc[i] >= k && inc[i + k] >= k) {
                    return true;
                }
            }
            return false;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFind(mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};