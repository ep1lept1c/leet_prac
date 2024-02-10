int ispal(char* s, int start, int end) {
    while (start <= end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
int countSubstrings(char* s) {
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (ispal(s, i, j)) {
                cnt++;
            }
        }
    }
    return cnt;
}
