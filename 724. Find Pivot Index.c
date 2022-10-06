// Link to the problem - https://leetcode.com/problems/find-pivot-index/

int pivotIndex(int* nums, int numsSize){

    int result = -1, index = 0;
    
    // We iterate intil we reach the end of the array or find a match
    while (index < numsSize && result == -1) {
        
        int sum_left = 0, sum_right = 0;
        
        // Iterate over the element to the left of the element
        for (int left_index = 0; left_index < index; ++left_index) {
            sum_left += nums[left_index];
        }
        
        // Iterate over the element to the right of the element
        for (int right_index = index + 1; right_index < numsSize; ++right_index) {
            sum_right += nums[right_index];
        }
        
        // Compare the values and change the result if they are the same
        if (sum_left == sum_right) {
            result = index;
        }
        
        ++index;
        
    }
    
    return result;
}
