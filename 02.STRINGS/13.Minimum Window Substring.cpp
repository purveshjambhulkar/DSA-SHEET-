class Solution {
public:
    string minWindow(string s1, string s2) {
        unordered_map<char, int> map;
        int min_len = INT_MAX; // Initialize to a large value
        int start_index = -1; 
        int left = 0;
        int count = 0;

        // Populate the map with the frequency of characters in s2
        for (char c : s2) {
            map[c]++;
        }
        int required = map.size(); // Number of unique characters in s2

        for (int right = 0; right < s1.length(); right++) {
            // Include the current character in the window
            if (map.find(s1[right]) != map.end()) {
                map[s1[right]]--;
                if (map[s1[right]] == 0) {
                    count++;
                }
            }

            // Try to shrink the window from the left
            while (count == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_index = left;
                }

                // Exclude the leftmost character from the window
                if (map.find(s1[left]) != map.end()) {
                    if (map[s1[left]] == 0) {
                        count--;
                    }
                    map[s1[left]]++;
                }
                left++;
            }
        }

        // If no valid window is found, return an empty string
        if (start_index == -1) {
            return "";
        }

        return s1.substr(start_index, min_len);

    }
};
