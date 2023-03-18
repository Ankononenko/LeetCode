/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize * 2;
    int* res = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        res[i] = nums[i];
        res[i + numsSize] = nums[i];
    }
    return res;
}
