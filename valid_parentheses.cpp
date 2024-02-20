class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }
            if (c == ')') {
                if (stack.empty() || stack.top() != '(') {
                    return false;
                }
                stack.pop();
            }
            if (c == ']') {
                if (stack.empty() || stack.top() != '[') {
                    return false;
                }
                stack.pop();
            }
            if (c == '}') {
                if (stack.empty() || stack.top() != '{') {
                    return false;
                }
                stack.pop();
            }
        }
        if (stack.empty()) {
            return true;
        }
        return false;
    }
};
