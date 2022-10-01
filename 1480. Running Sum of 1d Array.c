// Link to the problem - https://leetcode.com/problems/running-sum-of-1d-array/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    // Create a temporary array to hold the initial values of nums array
    // I want to return the nums array itself, the temp array is needed to not write modified values to the result
    int temp_array[numsSize];
    // Fill the temp array with default value - 0
    memset(temp_array, 0, numsSize * sizeof(int));
    // Copy the values from nums array to temp array
    for (int i = 0; i < numsSize; ++i) {
        temp_array[i] = nums[i];
    }
    // Add elements to the nums array
    for (int i = 1; i < numsSize; ++i) {
        for (int j = 0; j < i; ++j) {
           nums[i] += temp_array[j];
        }
    }
    *returnSize = numsSize;
    return nums;
}
