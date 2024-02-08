char* convert(char* s, int numRows) {
    int n = strlen(s);
    if (numRows == 1){
        return s;
    }
    char** zig = malloc(numRows * sizeof(*zig));
    for (int i = 0; i < numRows; i++) {
        zig[i] = malloc(sizeof(**zig) * n);
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < n; j++) {
            zig[i][j] = 0;
        }
    }
    int x = 0;
    int y = 0;
    int d = 1;
    for (int i = 0; i < n; i++){
        zig[x][y] = s[i];
        if (x == numRows - 1){
            d = -1;
        }
        if (x == 0){
            d = 1;
        }
        x += d;
        y += (d == -1) ? 1 : 0;
    }
    int cnt = 0;
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < n; j++){
            if (zig[i][j] != 0){
                s[cnt++] = zig[i][j];
            }
            
        }
    }
    return s;
}
