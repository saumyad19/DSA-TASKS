class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide window
        for (int i = k; i < nums.size(); i++) {

            sum += nums[i];       // new element
            sum -= nums[i - k];   // old element

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};