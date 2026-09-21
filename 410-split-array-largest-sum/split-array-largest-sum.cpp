class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            int parts = 1, sum = 0;

            for (int x : nums) {
                if (sum + x > mid) {
                    parts++;
                    sum = x;
                } else {
                    sum += x;
                }
            }

            if (parts > k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};