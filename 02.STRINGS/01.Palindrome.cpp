class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start <= end) {
            if (!isalnum(s[start]) || !isalnum(s[end])) {
                if (!isalnum(s[start])) {
                    start++;
                }
                if(!isalnum(s[end])){
                    end--;
                }
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int i = 0;
//         int j = s.length() - 1;
//         while (i < j) {
//             // Skip non-alphanumeric characters from the left
//             while (i < j && !isalnum(s[i])) {
//                 i++;
//             }
//             // Skip non-alphanumeric characters from the right
//             while (i < j && !isalnum(s[j])) {
//                 j--;
//             }
//             // Compare characters after skipping non-alphanumeric characters
//             if (tolower(s[i]) != tolower(s[j])) {
//                 return false;
//             }
//             // Move pointers inward
//             i++;
//             j--;
//         }
//         return true;
//     }
// };