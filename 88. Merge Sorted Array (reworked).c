void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int nums1_i = m - 1, nums2_i = n - 1, max_i = nums1Size - 1;
    while (nums1_i >= 0 && nums2_i >= 0) {
        if (nums1[nums1_i] >= nums2[nums2_i]) {
            nums1[max_i--] = nums1[nums1_i--];
        } else {
            nums1[max_i--] = nums2[nums2_i--];
        }
    }
    while (nums2_i >= 0) {
        nums1[max_i--] = nums2[nums2_i--];
    }
}
