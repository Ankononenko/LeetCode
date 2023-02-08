void get_right_sum(int* nums, int numsSize, int* right_sum);
void compare_sums(int* nums, int numsSize, int right_sum, int left_sum, int* pivot_index);

int pivotIndex(int* nums, int numsSize){

    int left_sum = 0, right_sum = 0, pivot_index = -1;
 
    get_right_sum(nums, numsSize, &right_sum);
    
    compare_sums(nums, numsSize, right_sum, left_sum, &pivot_index);
    
    return pivot_index;
}

void get_right_sum(int* nums, int numsSize, int* right_sum) {
    for (int index = 1; index < numsSize; ++index) {
        *right_sum += nums[index];
    }
}

void compare_sums(int* nums, int numsSize, int right_sum, int left_sum, int* pivot_index) {
    int index = 0, not_found = -1, right_sum_negative = 0;
    while (index < numsSize && *pivot_index == not_found) {
        if (left_sum == right_sum) {
            *pivot_index = index;
        }
        else {
            left_sum += nums[index];
            ++index;
            if (index < numsSize) {
                right_sum -= nums[index];
            }
        }
    }
}
