void moveZeroes(int* nums, int numsSize){
    int zeros = 0, write_index = 0;
    // Move elements and count zeros
    for (int read_index = 0; read_index < numsSize; ++read_index) {
        while (!nums[read_index] && read_index < numsSize - 1) {
            ++zeros;
            ++read_index;
        }
        nums[write_index] = nums[read_index];
        ++write_index;
    }
    // Insert zeros at the end
    if (zeros && numsSize != zeros) {
        int zero_index = numsSize - 1;
        for (int num_zeros = zeros; num_zeros > 0; --num_zeros) {
            nums[zero_index--] = 0;
        }
    }
}
