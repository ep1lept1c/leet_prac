int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int freq[256] = {0};
    int maxans = 0;
    int start = 0, end = 0;

    while (end < n) {
        if (freq[s[end]] == 0) {
            freq[s[end]]++;
            maxans = (maxans < end - start + 1) ? end - start + 1 : maxans;
            end++;
        } else {
            freq[s[start]]--;
            start++;
        }
    }

    return maxans;
}
