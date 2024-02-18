void qqsort(int* arr, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        int mid = arr[(left + right) / 2];
        do {
            while (arr[left] < mid)
                left++;
            while (arr[right] > mid)
                right--;
            if (left <= right) {
                int tmp = arr[right];
                arr[right] = arr[left];
                arr[left] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qqsort(arr, first, right);
        qqsort(arr, left, last);
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize,
              int** returnColumnSizes) {
                  int** rst;
    int rstSize = 0;
    int basicSize = 12;
    int a, b, c, d;
    long long sum;
    rst = malloc(sizeof(int*) * basicSize);
    *returnColumnSizes = malloc(sizeof(int) * basicSize);
    int preva = -1, prevb = -1, prevc = -1;
    qqsort(nums, 0, numsSize - 1);
    for (d = 0; d < numsSize - 3; d++) {
        if (d > 0 && nums[d] == nums[d - 1]) {
            continue;
        }
        for (a = d + 1; a < numsSize - 2; a++) {
            if (a > d + 1 && nums[a] == nums[a - 1]){
                continue;
            }
            b = a + 1;
            c = numsSize - 1;
            while (b < c) {
                sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                if (sum != (int) sum){
                    break;
                }
                if (sum == target) {
                    rst[rstSize] = (int*)malloc(sizeof(int) * 4);
                    (*returnColumnSizes)[rstSize] = 4;
                    rst[rstSize][0] = nums[a];
                    rst[rstSize][1] = nums[b];
                    rst[rstSize][2] = nums[c];
                    rst[rstSize][3] = nums[d];
                    rstSize++;
                    while (b < c && nums[b] == nums[b + 1]) {
                        b++;
                    }
                    b++;
                    c--;

                    if (rstSize == basicSize) {
                        basicSize *= 2;
                        rst = realloc(rst, sizeof(int*) * basicSize);
                        (*returnColumnSizes) = realloc((*returnColumnSizes),
                                                       sizeof(int) * basicSize);
                    }

                } else if (sum > target) {
                    c--;
                } else {
                    b++;
                }
            }
        }
    }

    *returnSize = rstSize;

    return rst;
}
