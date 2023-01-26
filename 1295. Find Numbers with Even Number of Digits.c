int find_len(int element);

int findNumbers(int* nums, int numsSize){
    int even_len_nums = 0, current_element_len = 0;
    for (int index = 0; index < numsSize; ++index) {
        current_element_len = find_len(nums[index]);
        if (!(current_element_len % 2)) {
            ++even_len_nums;
        }
    }
    return even_len_nums;
}

int find_len(int element) {
    int len = 0;
    while (element) {
        element /= 10;
        ++len;
    }
    return len;
}
