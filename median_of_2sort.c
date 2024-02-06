#include <limits.h>
int max(int v1, int v2){
    return (v1 > v2) ? v1 : v2;
}
int min(int v1, int v2){
    return (v1 < v2) ? v1 : v2;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size){
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int start = 0, end = nums1Size;
    int realmid = (nums1Size + nums2Size + 1) / 2;
    while (start <= end){
        int mid = (start + end)/2;
        int part1size = mid;
        int part2size = realmid - mid;
        int left1 = (part1size > 0) ? nums1[part1size - 1 ] : INT_MIN;
        int left2 = (part2size > 0) ? nums2[part2size - 1 ] : INT_MIN;
        int right1 = (part1size < nums1Size) ? nums1[part1size] : INT_MAX;
        int right2 = (part2size < nums2Size) ? nums2[part2size] : INT_MAX;
        if (left1 <= right2 && left2 <= right1){
            if ((nums1Size + nums2Size) % 2 == 0){
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } 
            return max(left1, left2);
        }else if (left1 > left2){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}
