/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void qqsort(int* arr, int first, int last){
    if (first < last){
        int left = first;
        int right = last;
        int mid = arr[(left + right)/2];
        do{
          while(arr[left] < mid) left++;
          while(arr[right] > mid) right--;
          if (left <= right){
              int tmp = arr[right];
              arr[right] = arr[left];
              arr[left] = tmp;
              left++;
              right--;
          }  
        }while (left <= right);
        qqsort(arr, first, right);
        qqsort(arr, left, last);
    }
}
int bbsearch(int* arr, int low, int high, int val){
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == val){
            return mid;
        }
        if (arr[mid] < val){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return 123456789;
    
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *copy = calloc(sizeof(copy), numsSize);
    for (int i = 0; i < numsSize; i++){
        copy[i] = nums[i];
    }
    qqsort(nums, 0, numsSize - 1);
    int* retarr = calloc(sizeof(retarr), 2);
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++){
        int x = nums[i];
        int check = bbsearch(nums, i + 1, numsSize - 1, target - x);
        if (check != 123456789){
            int flag = 1;
            for (int j = 0; j < numsSize; j++){
                if (copy[j] == x && flag){
                    retarr[0] = j;
                    flag = 0;
                }
                if (copy[j] == nums[check]){
                    retarr[1] = j;
                }
            }
            break;
        }
    }
    return retarr;
}
