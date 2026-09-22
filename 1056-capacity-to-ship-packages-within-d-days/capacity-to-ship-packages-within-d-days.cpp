class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            int need = 1, sum = 0;

            for (int w : weights) {
                if (sum + w > mid) {
                    need++;
                    sum = w;
                } else {
                    sum += w;
                }
            }

            if (need > days)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};