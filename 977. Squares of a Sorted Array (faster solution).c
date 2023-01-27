/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void square_and_sort_array(int* nums, int* array, int numsSize);

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    
    int *array;
    array = (int*) malloc (numsSize * sizeof(int));
    
    square_and_sort_array(nums, array, numsSize);
    
    *returnSize = numsSize;
    
    return array;
}

void square_and_sort_array(int* nums, int* array, int numsSize) {
    int min = 0, max = numsSize - 1, index = numsSize - 1;
    while (min <= max) {
    if (pow(nums[min], 2) >= pow(nums[max], 2)) {
        array[index--] = pow(nums[min++], 2);
    } else {
        array[index--] = pow(nums[max--], 2);
        }
    }
}
