#include <set>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> inter;
        for (auto num1 : nums1){
            for (auto num2 : nums2){
                if (num1 == num2){
                    inter.insert(num1);
                }
            }
        }
        std::vector<int> output;
        std::copy(inter.begin(), inter.end(), std::back_inserter(output));
        return output;
    }
};
