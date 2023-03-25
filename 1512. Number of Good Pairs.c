int numIdenticalPairs(int* nums, int numsSize){
    int res = 0;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i; j < numsSize; ++j) {
            if (j != i && nums[i] == nums[j]) {
                ++res;
            }
        }
    }
    return res;
}
