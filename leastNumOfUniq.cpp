class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::unordered_map<int, int> freqs;
        for (int elem : arr) {
            ++freqs[elem];
        }
        vector<pair<int, int>> newarr;
        for (auto& x : freqs) {
            newarr.push_back({x.second, x.first});
        }
        sort(newarr.rbegin(), newarr.rend());
        while (k > 0) {
            int minfreq = min(k, newarr.back().first);
            k -= minfreq;
            newarr.back().first -= minfreq;

            if (!newarr.back().first) {
                newarr.pop_back();
            }
        }
        return newarr.size();
    }
};
