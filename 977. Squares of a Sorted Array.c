/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void square_array(int* nums, int* array, int numsSize);
void sort_array(int* array, int numsSize);

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    
    int *array;
    array = (int*) malloc (numsSize * sizeof(int));
    
    square_array(nums, array, numsSize);
    sort_array(array, numsSize);
    
    *returnSize = numsSize;
    
    return array;
}

void sort_array(int* array, int numsSize) {
  int temp_num = 0;
  for (int index_i = 0; index_i < numsSize; ++index_i) {
    for (int index_j = index_i; index_j < numsSize; ++index_j) {
      if (array[index_j] < array[index_i]) {
        temp_num = array[index_i];
        array[index_i] = array[index_j];
        array[index_j] = temp_num;
      }
    }
  }    
}

void square_array(int* nums, int* array, int numsSize) {
    for (int index = 0; index < numsSize; ++index) {
        array[index] = nums[index] * nums[index];
    }
}
