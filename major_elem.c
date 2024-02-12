void quicksort(int *arr, int start, int end){
    if (start <= end){
        int left = start, right = end;
        int pivot = arr[(left + right) / 2];
        do{
            while (arr[left] < pivot) left++;
            while (arr[right] > pivot) right--;
            if (left <= right){
                int tmp = arr[right];
                arr[right] = arr[left];
                arr[left] = tmp;    
                right--;
                left++;
            }
        }while (left <= right);
        quicksort(arr,left, end);
        quicksort(arr,start, right);
    }
}
int majorityElement(int* nums, int numsSize) {
    quicksort(nums, 0, numsSize - 1);
    return nums[numsSize / 2];
}
