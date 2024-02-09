 void quicksort(int *arr, int left, int right){
     int start = left, end = right;
     if (start <= end){
         int pivot = arr[(start + end)/2];
         while (start <= end){
             while (arr[start] < pivot) start++;
             while (arr[end] > pivot) end--;
             if (start <= end){
                 int tmp = arr[start];
                 arr[start] = arr[end];
                 arr[end] = tmp;
                 start++;
                 end--;
             }
         }
         quicksort(arr, left, end);
         quicksort(arr, start, right);
     }
 }
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    quicksort(nums, 0, numsSize - 1);
    int *div = calloc(sizeof(*div), numsSize);
    int *prev = calloc(sizeof(*prev), numsSize);
    for (int i = 0; i < numsSize; i++){
        div[i] = 1;
        prev[i] = -1;
    }
    int max = 0;
    for (int i = 0; i < numsSize; i++){
        for (int j = 0; j < i; j++){
            if (nums[i] % nums[j] == 0){
                if (div[i] < div[j] + 1){
                    div[i] = div[j] + 1;
                    prev[i] = j;
                }
            }
        }
        if (div[max] < div[i]){
            max = i;
        }
    }
    int *ret = calloc(sizeof(*ret), div[max]);
    int k = max;
    *returnSize = div[max];
    int p = *returnSize - 1;
    while (k >= 0){
        ret[p--] = nums[k];
        k = prev[k];
    }
    return ret;
}
