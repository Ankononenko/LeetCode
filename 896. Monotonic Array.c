// Problem - https://leetcode.com/problems/monotonic-array/submissions/
// A lot of comments for peers who are learning to understand everything

// Copyright 2022 School 21 finchren

// The functions are used for easier to read code
int is_increasing(int previous, int current);
int is_decreasing(int previous, int current);

bool isMonotonic(int* nums, int numsSize){
    
    // Define a value to be returned and an index to iterate over the array of ints
    bool is_monotonic = true;
    int i = 1;
    // If there is only one element in the array or two, it's monotonic
    if (numsSize > 2) {
        // Here we decide whether the array is increasing or decreasing
        // There are going to be two ways to check the array and I need to decide which one to use
        int increasing = is_increasing(nums[i - 1], nums[i]);
        int decreasing = is_decreasing(nums[i - 1], nums[i]);

        if (increasing) {
            // "numsSize - 1" is used to not get out of bound of the array
            // In case with the last element, another ++i happens. I need to get rid of that error from happening
            while (i < numsSize - 1 && increasing) {
                ++i;
                    increasing = is_increasing(nums[i - 1], nums[i]);
                // If at some point we find that the array is no longer increasing, I stop and set is_monotonic to false
                // And continue if not
                if (!increasing) {
                    is_monotonic = false;
                    i = 0;
                } else {
                    is_monotonic = true;
                }
            }
        }
        
        if (decreasing) {
            while (i < numsSize - 1 && decreasing) {
                ++i;           
                decreasing = is_decreasing(nums[i - 1], nums[i]);
                if (!decreasing) {
                    is_monotonic = false;
                    i = 0;
                } else {
                    is_monotonic = true;
                }
            }
        }
    }
    return is_monotonic;
}

int is_increasing(int previous, int current) {
    // Elvis operator is used. If previous is bigger or equal to the current one,
    // Then reuturn 1, else 0
    return previous <= current ? 1 : 0;
}

int is_decreasing(int previous, int current) {
    return previous >= current ? 1 : 0;
}
