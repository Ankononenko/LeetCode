// Each line commented for peers, who may face difficulties solving this problem

int removeElement(int* nums, int numsSize, int val){
    // Variable used for the final result
    int final_number_of_elements = 0;
    // Index to insert the elements of nums array
    int insert_index = 0;
    // And index to iterate over the initial nums array
    int nums_index = 0;
    // Current element of the nums array to be compared with the val value
    int current_num = 0;
    // While loop to iterate over the array of nums,
    // Compare the values and write the array over
    while (nums_index < numsSize) {
        // Current num gets assigned the next element of the nums array
        current_num = nums[nums_index];
        // If the current element of nums array isn't equal to val value,
        // Add it to the array of nums starting from the begging and increase insert index by one
        if (current_num != val) {
            nums[insert_index] = current_num;
            ++insert_index;
        }
        // Index of the nums array incremented by one, so we could iterate over the array
        ++nums_index;
    }
    // Pass number of elements that are not equal to the val value to the final variable
    // This varible is used purely for it's name
    // We don't use it as index anymore, this is our final result now that gets returned from the function
    final_number_of_elements = insert_index;
    
    return final_number_of_elements;
}
