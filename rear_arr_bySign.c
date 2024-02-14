int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    *returnSize = n;
    int *rets = calloc(sizeof(*rets), n);
    int *pos = calloc(sizeof(*pos), n/2);
    int *neg = calloc(sizeof(*neg), n/2);
    int j = 0, k = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] < 0){
            neg[j++] = nums[i];
        }else{
            pos[k++] = nums[i];
        }
    }
    for (int i = 0; i < n/2; i++){
        rets[cnt++] = pos[i];
        rets[cnt++] = neg[i];
    }
    return rets;
}
