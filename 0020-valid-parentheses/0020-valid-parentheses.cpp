class Solution {
public:
    bool isValid(string s) {
        // Map to hold matching pairs of brackets
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        stack<char> stack;

        for (char c : s) {
            // If it's a closing bracket
            if (bracketMap.find(c) != bracketMap.end()) {
                // Check if the stack is empty or the top of the stack doesn't match
                if (stack.empty() || stack.top() != bracketMap[c]) {
                    return false;
                }
                // Pop the top element from the stack
                stack.pop();
            } else {
                // If it's an opening bracket, push it onto the stack
                stack.push(c);
            }
        }

        // If the stack is empty at the end, all brackets are matched
        return stack.empty();
    }
};