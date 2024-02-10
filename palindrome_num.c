bool isPalindrome(int x) {
    if (x < 0) return false;
    int px = 0, copx = x;
    while (copx > 0){
        if (__builtin_smul_overflow(px,10, &px)) return false;
        if (__builtin_add_overflow(px, copx % 10, &px)) return false;
        copx /= 10;
    }
    return (x == px);
}
