class Solution {
public:
    int lengthOfLastWord(string s) {
        string str;
        stringstream ss(s); 
        int len = 0;
        while (ss>>str){
            len = str.length();
        }
        return len;
    }
};
