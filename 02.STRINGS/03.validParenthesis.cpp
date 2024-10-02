class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // stack to hold opening brackets
        for (int i = 0; i < s.length(); i++) {
            // Push opening brackets onto the stack
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            } 
            // For closing brackets
            else {
                // If stack is empty, return false (no matching opening bracket)
                if (st.empty()) return false;
                
                char top = st.top();  // Get the top of the stack
                
                // Check if the top of the stack matches the current closing bracket
                if ((top == '[' && s[i] == ']') ||
                    (top == '{' && s[i] == '}') ||
                    (top == '(' && s[i] == ')')) {
                    st.pop();  // Valid match, pop the opening bracket
                } 
                else {
                    return false;  // Mismatch found, return false
                }
            }
        }
        // Stack should be empty if all brackets are balanced
        return st.empty();
    }
};
