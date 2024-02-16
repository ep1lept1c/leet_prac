class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> str;
        if (digits == ""){
            return str;
        }
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            if (s.length() == digits.length()) {
                str.push_back(s);
            } else {
                int n = digits[s.length()] - '0';
                for (auto letter : phone[n]){
                    q.push(s + letter);
                }
            }
        }
        return str;
    }
};
