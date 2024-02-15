void quicksort(int *arr, int start, int end){
    if (start <= end){
        int left = start, right = end;
        int pivot = arr[(left + right)/2];
        while (left <= right){
            while (arr[left] < pivot) left++;
            while (arr[right] > pivot) right--;
            if (left <= right){
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        }
        quicksort(arr, left, end);
        quicksort(arr, start, right);
    }
}
long long largestPerimeter(int* nums, int n) {
    quicksort(nums, 0, n-1);
    long long checksum = 0, ret = -1;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (k >= 2 &&  checksum > nums[i]){
            ret = checksum + nums[i];
        }
        checksum += nums[i];
        k++;
    }
    return ret;
}
