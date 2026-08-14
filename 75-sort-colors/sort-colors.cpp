class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        // Count 0, 1, 2
        for(int x : nums) count[x]++;
        // Fill array
        int i = 0;
        while(count[0]--) nums[i++] = 0;
        while(count[1]--) nums[i++] = 1;
        while(count[2]--) nums[i++] = 2;
    }
};