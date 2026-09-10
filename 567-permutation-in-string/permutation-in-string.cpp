class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for (char c : s1)
            freq1[c - 'a']++;

        int k = s1.length();

        for (int i = 0; i < s2.length(); i++) {

            // Add current character
            freq2[s2[i] - 'a']++;

            // Keep window size = k
            if (i >= k)
                freq2[s2[i - k] - 'a']--;

            // Compare frequencies
            if (i >= k - 1 && equal(freq1, freq2))
                return true;
        }

        return false;
    }

    bool equal(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
};