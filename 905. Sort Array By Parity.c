int is_odd(const int num);

int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int start_index = 0, end_index = numsSize - 1, temp_element = 0;
    while (start_index < end_index) {
        if (is_odd(nums[start_index]) & !is_odd(nums[end_index])) {
            temp_element = nums[start_index];
            nums[start_index++] = nums[end_index];
            nums[end_index--] = temp_element;
        } else if (!is_odd(nums[start_index]) & !is_odd(nums[end_index])) {
            ++start_index;
        } else if (is_odd(nums[start_index]) & is_odd(nums[end_index])) {
            --end_index;
        } else {
            ++start_index;
            --end_index;
        }
    }
    *returnSize = numsSize;
    return nums;
}

int is_odd(const int num) {
    return num % 2;
}
