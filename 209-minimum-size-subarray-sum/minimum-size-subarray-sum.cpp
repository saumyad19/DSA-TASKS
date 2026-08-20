class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0; int minLen = INT_MAX;
        int n = nums.size(); long long sum = nums[0];
        while (r < n) {
            while (l <= r && sum >= target) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
            if (r < n) sum += nums[r];
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};