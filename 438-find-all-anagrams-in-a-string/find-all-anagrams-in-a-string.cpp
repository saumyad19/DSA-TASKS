class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;
        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        for (char ch : p) {
            freqP[ch - 'a']++;
        }
        int k = p.size();
        for (int i = 0; i < s.size(); i++) {
            // Add current character
            freqS[s[i] - 'a']++;
            // Remove character outside window
            if (i >= k) {
                freqS[s[i - k] - 'a']--;
            }
            // Window size becomes k
            if (i >= k - 1 && freqS == freqP) {
                ans.push_back(i - k + 1);
            }
        }
        return ans;
    }
};