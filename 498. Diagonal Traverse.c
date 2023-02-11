int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    *returnSize = matSize * (*matColSize);
    int* ret_array;
    ret_array = (int*) malloc (*returnSize * sizeof(int));
    memset(ret_array, 0, *returnSize * sizeof(int));
    // TODO: [[1],[2]]
    int insert_index = 0;
    if (matSize == *matColSize && matSize > 1 && *matColSize > 1) {
        printf("matSize = %d, matColSize = %d\n", matSize, *matColSize);
        int row_counter = 0, element_i = 0;

        // remove
        int num_elements = 0;

        for (int row_i_start = 0; row_i_start < matSize - 1; ++row_i_start) {
            if (row_counter % 2) {
                element_i = row_i_start;
                for (int row_i_end = 0; row_i_end <= row_i_start; ++row_i_end) {
                    ret_array[insert_index++] = mat[row_i_end][element_i];
                    printf("%d %d, ", row_i_end, element_i);
                    --element_i;
                    ++num_elements;
                }
                ++row_counter;
            } else {
                element_i = 0;
                for (int row_i_end = row_i_start; row_i_end >= 0; --row_i_end) {
                    ret_array[insert_index++] = mat[row_i_end][element_i];
                    printf("%d %d, ", row_i_end, element_i);
                    ++element_i;
                    ++num_elements;
                }
                ++row_counter;
            }
            printf("\n");
        }
        
        for (int row_i_start = 0; row_i_start < matSize; ++row_i_start) {
            if (row_counter % 2) {
                element_i = matSize - 1;
                for (int row_i_end = row_i_start; row_i_end <= matSize - 1; ++row_i_end) {
                    ret_array[insert_index++] = mat[row_i_end][element_i];
                    printf("%d %d, ", row_i_end, element_i);
                    --element_i;
                    ++num_elements;
                }
                ++row_counter;
            } else {
                element_i = row_i_start;
                for (int row_i_end = matSize - 1; row_i_end >= row_i_start; --row_i_end) {
                    ret_array[insert_index++] = mat[row_i_end][element_i];
                    printf("%d %d, ", row_i_end, element_i);
                    ++element_i;
                    ++num_elements;
                }
                ++row_counter;
            }
            printf("\n");
        }
        printf("num elements = %d\n", num_elements);
    } if (matSize == 1) {
        for (int index = 0; index < *matColSize; ++index) {
            ret_array[insert_index++] = mat[0][index];
        }
    } if (matSize != *matColSize) {
        int total_sum_iterations = matSize + *matColSize - 1;
        int equal_row_iterations = total_sum_iterations - ((*matColSize) * 2);
        printf("sum = %d, equal = %d\n", total_sum_iterations, equal_row_iterations);
        int row_index = 0, row_counter = 0;
        // Going up
        for (; row_index < *matColSize; ++row_index) {
            for (int row_index_end = row_index; row_index_end >= 0; --row_index_end) {
                printf("up %d ", row_index_end);
            }
            ++row_counter;
            printf("\n");
        }
        // Staying the same size
        int equal_rows_printed = 0, row_index_equal_up_end = 0;
        if (matSize > 3) {
            ++row_index_equal_up_end;
        }
        while (equal_rows_printed <  equal_row_iterations) {
            for (int row_index_equal_start = row_index; row_index_equal_start >= row_index_equal_up_end; --row_index_equal_start) {
                printf("same %d ", row_index_equal_start);
            }
            if (matSize > 3) {
                ++row_index;
                ++row_index_equal_up_end;
            }
            ++row_counter;
            ++equal_rows_printed;
            printf("\n");
        }
        // Going down
        --row_index_equal_up_end;
        while (row_counter != total_sum_iterations) {
            for (int index = row_index; index > row_index_equal_up_end; --index) {
                    printf("down %d ", index);
            }
            printf("\n");
            ++row_index_equal_up_end;
            ++row_counter;
        }
    }
    return ret_array;
}

