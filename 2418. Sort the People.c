char ** sortPeople(char ** names, int namesSize, int* heights, int heightsSize, int* returnSize){
    int temp_height = 0, res_insert_i = 0, cur_max = 0, cur_max_i = 0;
    char** res = (char**)malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; ++i) {
        cur_max = heights[0];
        cur_max_i = 0;
        for (int j = 0; j < namesSize; ++j) {
            if (cur_max < heights[j]) {
                cur_max = heights[j];
                cur_max_i = j;
            }
        }
        res[res_insert_i] = (char*)malloc(strlen(names[cur_max_i]) + 1);
        strcpy(res[res_insert_i], names[cur_max_i]);
        ++res_insert_i;
        heights[cur_max_i] = 0;
    }
    *returnSize = namesSize;
    return res;
}
