int search(int* nums, int numsSize, int target){

    int result = -1, index = 0;
    
    // Iterate while the index is less than the size of the nums array
    // And until the current nums element is less or equal to the target
    // Because by the condition of the problem the array is linear
    while (index < numsSize && nums[index] <= target) {
        
        if (target == nums[index]) {
            result = index;
        }
        
        ++index;
    }
    
    return result;
    
}
