void add_nums2_to_nums1(int* nums1, int nums1Size, int m, int* nums2);
void sort_nums1(int* nums1, int nums1Size);

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    add_nums2_to_nums1(nums1, nums1Size, m, nums2);
    sort_nums1(nums1, nums1Size);
}

void sort_nums1(int* nums1, int nums1Size) {
    int temp_arr[nums1Size];
    for (int index = 0; index < nums1Size; ++index) {
        temp_arr[index] = nums1[index];
    }
    int min = 0, temp = 0;
    for (int index_i = 0; index_i < nums1Size; ++index_i) {
        min = temp_arr[index_i];
        for (int index_j = index_i + 1; index_j < nums1Size; ++index_j) {
            if (temp_arr[index_j] < min) {
                temp = min;
                min = temp_arr[index_j];
                temp_arr[index_j] = temp;
            }
        }
    nums1[index_i] = min;
    }
}

void add_nums2_to_nums1(int* nums1, int nums1Size, int m, int* nums2) {
    int index_nums2 = 0;
    for (int index_nums1 = m; index_nums1 < nums1Size; ++index_nums1) {
        nums1[index_nums1] = nums2[index_nums2++];
    }
}
