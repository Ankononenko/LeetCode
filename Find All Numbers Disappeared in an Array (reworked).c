int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

    int temp = 0;
    
    for (int index = 0; index < numsSize; ++index) {
        temp = abs(nums[index]) - 1;
        nums[temp] = abs(nums[temp]) * -1;
    }
    
    int insert_index = 0;

    *returnSize = 0;
    for (int index = 0; index < numsSize; ++index) {
        if (nums[index] > 0) {
            ++*returnSize;
            nums[insert_index++] = index + 1;
        }
    }
    
    return nums;
}
