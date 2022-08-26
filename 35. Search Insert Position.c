// Boolean enum to create easy to read while-loop condition
enum boolean{
    FALSE,
    TRUE
};

int searchInsert(int* nums, int numsSize, int target){
    // Final index of the target element to be returned from the function
    int target_index = 0;
    // Index of the nums array to iterate over each element until we meet the target element
    int nums_index = 0;
    // Index of the last element of nums array
    int last_element_index = numsSize - 1;
    // Used as a switch for the while loop. The while loop stops iterating as soon as the condition is met
    int should_run = TRUE;
    // Iterate over the array of nums with a while loop
    // We go up the array until the current element equals to the target or is bigger than the target value
    // While loop is also stopped if we reach the end of the nums array and don't find the target element
    while (should_run) {
        if (nums[nums_index] < target && nums_index != last_element_index) {
            // Increase the index of the nums array
            ++nums_index;    
        } else {
            // If the target element was found or the array has ended, we exit the loop
            should_run = FALSE;
        }
    }
    // Here we use an Elvis operator
    // If the target wasn't found when we reached the end of nums array, the target_index equals to the max index of array plus one
    // If we find the target element the target_index equals the current index (nums_index) of array of nums
    target_index = nums_index == last_element_index && nums[nums_index] < target ? ++nums_index : nums_index;
    
    return target_index;
}
