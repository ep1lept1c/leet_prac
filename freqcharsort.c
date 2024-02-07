int findmax(int* arr, int n) {
    int max = -1;
    int maxind = 0;
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}
char* frequencySort(char* s) {
    int freq[128] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[(int)s[i]]++;
    }
    int howmuch = 0;
    char symbol;
    while ((symbol = findmax(freq,128)) != 0){
        for (int j = 0; j < freq[symbol]; j++) {
                s[howmuch + j] = symbol;
            }
        howmuch += freq[symbol];
        freq[symbol] = 0;
    }
    return s;
}
