class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int minlen = strs[0].length();
        for (string str : strs){
            int len = str.length();
            minlen = (minlen < len) ? minlen : len;
        }
        for (int i = 0; i < minlen; i++){
            ans += strs[0][i];
            for (string str : strs){
                if (str[i] != ans[i]){
                    ans.pop_back();
                    return ans;
                }
            }
        }
        return ans;
    }
};
