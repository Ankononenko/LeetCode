int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max_consecutive = 0, current_consecutive = 0;
    for (int index = 0; index < numsSize; ++index) {
        if (nums[index]) {
            ++current_consecutive;
        }
        if (!(nums[index]) || index == numsSize - 1) {
            if (current_consecutive > max_consecutive) {
                max_consecutive = current_consecutive;
            }
            current_consecutive = 0;
        }
    }
    return max_consecutive;
}
