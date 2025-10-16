#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            int r = ((x % value) + value) % value;
            freq[r]++;
        }

        int i = 0;
        while (true) {
            int r = i % value;
            if (freq[r] > 0) {
                freq[r]--;
                i++;
            } else {
                return i;
            }
        }
    }
};
