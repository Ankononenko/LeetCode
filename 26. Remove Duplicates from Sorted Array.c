// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

int removeDuplicates(int* nums, int numsSize){
    
    // Length of unique elements to be returned from the function
    int n_of_unique_elements = 0;
    
    // We only start to find the elements if the size of incomming array is more than one element
    if (numsSize > 1) {
        
        // First one - index of incomming array of nums, second - index to write unique element to
        int nums_index = 0, index_to_write_to = 0;
        // Current and previous element, we compare them to find unique elements and reasign them as we move up
        int previous_element = nums[nums_index], current_element = nums[nums_index + 1];

        // While the array of nums hasn't ended we compare the values of elements
        while (nums_index != numsSize) {
            // If elements are not equal, we overwrite the incomming array of nums and increase the index to write to
            if (current_element != previous_element) {
                nums[index_to_write_to] = previous_element;
                ++index_to_write_to;
            }
            // The index of array of nums gets increased and elements get reassigned to keep moving up the nums array
            ++nums_index;
            previous_element = current_element;
            // If element is the last one, don't assign the next value. Otherwise we will get garbage in the next element variable
            if (nums_index != numsSize) {
                current_element = nums[nums_index];
            }
        }

        // Since the last element can't be compared with anything, we write it to the array and increase the index
        nums[index_to_write_to] = previous_element;
        ++index_to_write_to;

        // Assign index of unique elements written to the variable that we return from the function. Used purely to create the easiest to read code
        n_of_unique_elements = index_to_write_to;
        
    } else {
        // If size of array is less than one element we return the array and it's size as is
        n_of_unique_elements = numsSize;
    }

    return n_of_unique_elements;
    
}
