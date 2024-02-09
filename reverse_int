#include <limits.h>
int reverse(int x){
    int revx = 0;
    int sign = (x < 0) ? -1: 1;
    if (x == INT_MIN){
        return 0;
    }
    x = (x > 0) ? x : -x;
    while (x > 0){
        if(__builtin_smul_overflow(revx, 10, &revx)) return 0;
        if(__builtin_add_overflow(revx, x % 10, &revx)) return 0;
        x /= 10;
    }
    revx *= sign;
    return revx;
}
