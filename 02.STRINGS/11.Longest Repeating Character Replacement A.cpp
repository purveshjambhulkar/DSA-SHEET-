class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq; // To track frequency of characters in the current window
        int max_freq = 0; // Maximum frequency of a single character in the current window
        int left = 0; // Left pointer of the sliding window
        int max_len = 0; // Maximum length of the valid substring

        for (int right = 0; right < n; ++right) {
            // Add the current character to the frequency map
            freq[s[right]]++;
            max_freq = max(max_freq, freq[s[right]]);

            // Check if the current window is valid
            while ((right - left + 1) - max_freq > k) {
                freq[s[left]]--; // Remove the character at the left pointer
                left++; // Shrink the window
            }

            // Update the maximum length
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
