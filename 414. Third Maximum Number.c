int thirdMax(int* nums, int numsSize){
    int first_max = nums[0], second_max = INT_MIN, third_max = INT_MIN;
    // Find first max
    for (int index = 0; index < numsSize; ++index) {
        if (nums[index] > first_max) {
            first_max = nums[index];
        }
    }
    // Find second max
    if (numsSize >= 2) {
        for (int index = 0; index < numsSize; ++index) {
            if (nums[index] > second_max && nums[index] < first_max) {
                second_max = nums[index];
            }
        }
    }
    // Create an array to check if there are 3 different numbers in the array of nums
    int* three;
    three = (int*)malloc(3 * sizeof(int));
    int three_index = 0;
    three[three_index++] = nums[0];
    for (int index_i = 0; index_i < numsSize; ++index_i) {
        for (int index_j = 0; index_j < three_index; ++index_j) {
            if (three[index_j] == nums[index_i]) {
                break;
            }
            if (index_j == three_index - 1) {
                three[three_index] = nums[index_i];
                ++three_index;
            }
        }
        if (three_index == 3) {
            break;
        }
    }

    // Find the third max
    if (numsSize >= 3) {
        for (int index = 0; index < numsSize; ++index) {
            if (nums[index] > third_max && nums[index] < second_max) {
                third_max = nums[index];
            }
        }
    }
    if (three_index == 3) {
        free(three);
        return third_max;
    }
    free(three);
    return first_max;
}
