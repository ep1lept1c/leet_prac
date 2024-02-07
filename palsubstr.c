int ispal(char *s, int start, int end){
    while (start <= end){
        if (s[start] != s[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (ispal(s, 0, n - 1)){
        return s;
    }
    int maxlen = 0;
    char *maxpal = calloc(sizeof(*maxpal), n);;
    for (int i = 0; i < n; i++){
        for (int j = n - 1; j >= i; j--){
            if (ispal(s, i, j)){
                if (maxlen < j - i + 1){
                    maxlen = j - i + 1;
                    for (int k = 0; k < maxlen; k++){
                        maxpal[k] = s[k + i];
                    }
                }
                break;
            }
        }
    }
    return maxpal;
}
