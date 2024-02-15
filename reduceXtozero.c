int max(int v1, int v2){
    return (v1 > v2) ? v1 : v2;
}
int minOperations(int* nums, int n, int x) {
    int total = 0;
    for (int i = 0; i < n; i++){
        total += nums[i];
    }
    int left = 0, right = 0, cnt = 0;
    if (total == x) return n;
    total -= x;
    int sum = 0;
    while (right < n){
        sum += nums[right];
        while (left < right && sum > total){
            sum -= nums[left];
            left++;
        }
        if (sum == total){
            cnt = max(cnt, right - left + 1);
        }
        right++;
    }
    return (cnt == 0) ? -1 : n - cnt;
}
