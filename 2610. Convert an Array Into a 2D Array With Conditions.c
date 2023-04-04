int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int max_num_matrixes = 0;
    int* all_nums = (int*)calloc(numsSize + 1, sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        all_nums[nums[i]] += 1;
        max_num_matrixes = all_nums[nums[i]] > max_num_matrixes ? all_nums[nums[i]] : max_num_matrixes;
    }
    *returnSize = max_num_matrixes;
    int** ret = (int**)malloc(*returnSize * sizeof(int*));
    int current_size, insert_i;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int num_mat = 0; num_mat < max_num_matrixes; ++num_mat) {
        current_size = 1;
        insert_i = 0;
        ret[num_mat] = (int*)malloc(current_size * sizeof(int));

        for (int i = 0; i <= numsSize; ++i) {
            if (all_nums[i]) {
                ++current_size;
                ret[num_mat] = (int*)realloc(ret[num_mat], sizeof(int) * current_size);
                ret[num_mat][insert_i] = i;
                --all_nums[i];
                ++insert_i;
            }
        }
        (*returnColumnSizes)[num_mat] = insert_i; 
    }
    return ret;
}
