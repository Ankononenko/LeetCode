int removeDuplicates(int* nums, int numsSize){
    int write_index = 0;
    for (int index = 1; index < numsSize; ++index) {
        if (nums[index] > nums[write_index]) {
            nums[++write_index] = nums[index];
        }
    }
    return ++write_index;
}
