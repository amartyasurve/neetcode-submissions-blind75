class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack; // Stores indices of '('
        stack<int> starStack; // Stores indices of '*'
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openStack.push(i);
            } else if (s[i] == '*') {
                starStack.push(i);
            } else { // It's a ')'
                if (!openStack.empty()) {
                    openStack.pop(); // Prefer matching with '('
                } else if (!starStack.empty()) {
                    starStack.pop(); // Fallback to '*'
                } else {
                    return false; // No '(' or '*' to match the ')'
                }
            }
        }
        
        // Match remaining '(' with '*'
        while (!openStack.empty() && !starStack.empty()) {
            // If the '(' appears AFTER the '*', it's invalid (e.g., "*(")
            if (openStack.top() > starStack.top()) {
                return false;
            }
            openStack.pop();
            starStack.pop();
        }
        
        // If there are unmatched '(' left over, it's invalid
        return openStack.empty();
    }
};