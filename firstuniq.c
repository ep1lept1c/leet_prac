int firstUniqChar(char* s) {
    int len = strlen(s);
    if (len == 1)
        return 0;
    char* alph = calloc(sizeof(*alph), 26);
    for (int i = 0; i < len; i++) {
        int uniq = 1;
        if (!alph[(int)(s[i] - 97)]) {
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    alph[(int)(s[i] - 97)] = 1;
                    uniq = 0;
                    break;
                }
            }
            if (uniq) {
                return i;
            }
        }
    }
    return -1;
}
