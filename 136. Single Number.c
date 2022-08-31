int singleNumber(int* nums, int numsSize){
    int result = 0, is_found = 0, end_for_loop = 0;
    // Iterate over each element
    for (int i = 0; i < numsSize; ++i) {
        is_found = 0;
        // And compare each of the elements with all elements if the 
        for (int j = 0; j < numsSize; ++j) {
            result = nums[i];
            // Increment is_found by one each time a value has been found
            if (result == nums[j]) {
                ++is_found;
            }
            // If we found only one number in the array of that kind,
            // Then we've found the number that we have been searching for
            if (is_found == 1 && j == numsSize - 1) {
                // This variable is used to exit the parent for-loop
                end_for_loop = 1;
            }
        }
        if (end_for_loop) {
            break;
        }
    }
    return result;
}
