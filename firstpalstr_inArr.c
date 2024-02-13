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

char* firstPalindrome(char** words, int wordsSize) {
    for (int i = 0; i < wordsSize; i++){
        int len = strlen(words[i]);
        if(ispal(words[i], 0, len - 1)){
            return words[i];
        }
    }
    return "";
}
