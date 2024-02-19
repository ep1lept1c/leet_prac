bool isPowerOfTwo(int n) {
    long long x = n;
    if (n && !(n & (x - 1))) return true;
    return false;
}
