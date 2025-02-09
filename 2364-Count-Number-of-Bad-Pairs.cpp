class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total = (1LL * n * (n - 1)) / 2; // Fix overflow
        unordered_map<int, int> mpp;
        long long good = 0;
        for (int i = 0; i < n; i++) {
            int diff = i - nums[i];
            good += mpp[diff];
            mpp[diff]++;
        }
        return total - good;
    }
};
