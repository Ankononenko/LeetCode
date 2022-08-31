int singleNumber(int* nums, int numsSize){
    int result = 0;
    // We iterate over the array while there are elements
    // And compare the values using the XOR operator
    // It is bitwise comparison, meaning that the result of the whole iteration
    // Is going to be the difference in bits between the all of elements
    // Which in the end is going to be that one element that doesn't have a pair
    while(numsSize--) result ^= nums[numsSize];
    return result;
}
