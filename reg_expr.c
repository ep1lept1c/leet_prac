bool isMatch(char* s, char* p) {
    int slen = strlen(s), plen = strlen(p);
    int ret[21][21];
    for (int i = 0; i <= slen; i++){
        for (int j = 0; j <= plen; j++){
            ret[i][j] = 0;
        }
    }
    ret[0][0] = 1;
    for (int i = 2; i <= plen; i++) {
        if (p[i - 1] == '*') {
            ret[0][i] = ret[0][i - 2];
        }
    }
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= plen; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                ret[i][j] = ret[i - 1][j - 1];
            } else if (j > 1 && p[j - 1] == '*') {
                ret[i][j] = ret[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    ret[i][j] = ret[i][j] || ret[i - 1][j];
                }
            }
        }
    }
    return ret[slen][plen];
}
