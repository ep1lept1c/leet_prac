class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long res = 0;
        for (int i = 0; i < 32; i++){
            long long bit = (left >> i) & 1;
            if (!bit){
                continue;
            }
            long long diff = (long long)(1 << (i + 1)) - (left % (1 << (i + 1)));
            
            if (right - left < (int)diff){
                res |= (1 << i);
            }
        }
        return (int)res;
    }
};
