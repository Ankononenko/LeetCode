void find_max(int* nums, int numsSize, int* max, int* max_index);
void find_less_than_max(int* nums, int numsSize, int max, long int* less_than_max);

int dominantIndex(int* nums, int numsSize) {

    int max = nums[0], max_index = 0;
    long int less_than_max = INT_MIN;

    find_max(nums, numsSize, &max, &max_index);    
    find_less_than_max(nums, numsSize, max, &less_than_max);

    max_index = less_than_max * 2 <= max ? max_index : -1;
    
    return max_index;
}

void find_max(int* nums, int numsSize, int* max, int* max_index) {
    for (int index = 0; index < numsSize; ++index) {
        if (nums[index] > *max) {
            *max = nums[index];
            *max_index = index;
        }
    }
}

void find_less_than_max(int* nums, int numsSize, int max, long int* less_than_max) {
    for (int index = 0; index < numsSize; ++index) {
        if (nums[index] < max && nums[index] > *less_than_max) {
            *less_than_max = nums[index];
        }
    }
}
