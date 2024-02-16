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
int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k, sum, close;
    qqsort(nums, 0, numsSize - 1);
    int closest = INT_MAX, closestsum = 0;
    for (i = 0; i < numsSize - 1; i++) {
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            close = abs(target - sum);
            if (sum > target) {
                k--;
            } else {
                j++;
            }
            if (close < closest){
                closest = close;
                closestsum = target - sum;
            }
        }
    }
    return target - closestsum;
}
