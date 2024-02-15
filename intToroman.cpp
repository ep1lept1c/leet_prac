class Solution {
public:
    string intToRoman(int num) {
        string Roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for (int i = 0; i < 13 && num >= 0; i++){
            while (num - val[i] >= 0){
                num -= val[i];
                ans += Roman[i];
            }
        }
        return ans;
    }
};
