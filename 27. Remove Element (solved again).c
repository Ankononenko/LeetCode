int removeElement(int* nums, int numsSize, int val){
    int temp_index = 0, k = 0;
    for (int index = 0; index < numsSize; ++index) {
        if (nums[index] == val) {
            temp_index = index;
            while (nums[temp_index] == val) {
                if (temp_index == numsSize - 1) {
                    return k;
                }
                ++temp_index;
            }
            nums[index] = nums[temp_index];
            nums[temp_index] = val;
            ++k;
        } else {
            ++k;
        }
    }
    return k;
}
