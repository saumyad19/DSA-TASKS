class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (int num : st) {
            // Check if num is the starting point
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int count = 1;
                // Find consecutive numbers
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};