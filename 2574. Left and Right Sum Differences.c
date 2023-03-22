int* leftRigthDifference(int* nums, int numsSize, int* returnSize){
    int* res = (int*)malloc(numsSize * sizeof(int));
    int* right_sum = (int*)malloc(numsSize * sizeof(int));
    int cur_num;
    // Fill in the right sum arr
    for (int i = 0; i < numsSize; ++i) {
        cur_num = 0;
        for (int j = i + 1; j < numsSize; ++j) {
            cur_num += nums[j];
        }
        right_sum[i] = cur_num;
    }
    int* left_sum = (int*)malloc(numsSize * sizeof(int));
    // Fill in the left sum arr
    for (int i = 0; i < numsSize; ++i) {
        cur_num = 0;
        for (int j = 0; j < i; ++j) {
            cur_num += nums[j];
        }
        left_sum[i] = cur_num;
    }
    // Fill in the res arr
    for (int i = 0; i < numsSize; ++i) {
        res[i] = left_sum[i] - right_sum[i];
        res[i] = res[i] < 0 ? res[i] * -1 : res[i];
    }
    free(right_sum);
    free(left_sum);
    *returnSize = numsSize;
    return res;
}
