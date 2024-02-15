class Solution {
public:
    int romanToInt(string s) {
        string Roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int ans = 0;
        int pos = 0;
        for (int i = 0; i < 13; i++){
            while (s.find(Roman[i], pos) == pos){
                pos += Roman[i].length();
                ans += val[i];
            }
        }
        return ans;
    }
};
