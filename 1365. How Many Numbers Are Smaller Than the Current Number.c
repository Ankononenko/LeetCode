int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* res = (int*)malloc(*returnSize * sizeof(int));
    int current_num, res_num;
    for (int i = 0; i < *returnSize; ++i) {
        res_num = 0;
        current_num = nums[i];
        for (int j = 0; j < *returnSize; ++j) {
            if (nums[j] < current_num) {
                ++res_num;
            }
        }
        res[i] = res_num;
    }
    return res;
}
