int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    
    // Temp array to store which values are present in nums array
    int* temp_arr;
    temp_arr = (int*) malloc (numsSize * sizeof(int));
    memset(temp_arr, 0, numsSize * sizeof(int));
    int temp_arr_index = 0;
    *returnSize = numsSize;

    // Iterate over nums and insert into the temp_array's indexes those values that are present
    for (int index = 0; index < numsSize; ++index) {
        temp_arr_index = nums[index] - 1;
        if (!temp_arr[temp_arr_index]) {
            temp_arr[temp_arr_index] = true;
            --*returnSize;
        }
    }

    // Iterate over temp_array and write to nums those values that were not present
    int insert_index = 0;
    for (int index = 1; index <= numsSize; ++index) {
        if (!temp_arr[index - 1]) {
            nums[insert_index++] = index;
        }
    }
    return nums;
}
