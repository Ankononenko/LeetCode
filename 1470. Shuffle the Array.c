int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = n * 2;
    int* ret_arr = (int*)malloc(*returnSize * sizeof(int));
    int x_read_i = 0, y_read_i = n;
    for (int i = 0; i < *returnSize; ++i) {
        ret_arr[i++] = nums[x_read_i++];
        ret_arr[i] = nums[y_read_i++];
    }
    return ret_arr;
}
