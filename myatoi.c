int myAtoi(char* s) {
    int res = 0;
    int sign = 1;
    int rf = 0;
    int pfl = 0;
    while (*s){
        rf = 0;
        char c = *s++;
        if (c == '-'){
            if (pfl){
                return res * sign;
            }
            pfl = 1;
            sign = -1;
            rf = 1;
        }
        if (c == '+'){
            if (pfl){
                return res * sign;
            }
            pfl = 1;
            rf = 1;
            continue;
        }
        if (c == ' '){
            if (pfl){
                return res * sign;
            }
            rf = 1;
            continue;
        }
        if (c >= '0' && c <= '9'){
            pfl = 1;
            rf = 1;
            int x = c - '0';
            if(__builtin_smul_overflow(res, 10, &res)){ 
                return (sign > 0) ? INT_MAX : INT_MIN;
            }
            if(__builtin_add_overflow(res, x, &res)){
                return (sign > 0) ? INT_MAX : INT_MIN;
            }
        }
        if (!rf){
            return res * sign;
        }
    }
    return res * sign;
}
