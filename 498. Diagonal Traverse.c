int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    *returnSize = matSize * (*matColSize);
    int* ret_array;
    ret_array = (int*) malloc (*returnSize * sizeof(int));
    
    memset(ret_array, 0, *returnSize * sizeof(int));
    
    // Iterate up
    /*  0_0
        0_1 1_0
        0_2 1_1 2_0
        
        Your stdout
        row = 0, element 0; 
        row = 0, element 1; row = 1, element 0; 
        row = 0, element 2; row = 1, element 1; row = 2, element 0; 
        
        Your input
        [[1,2,3],[4,5,6],[7,8,9]]
        
        Expected answer
        [1,2,4,7,5,3,6,8,9]
        
        Your answer
        [1,2,4,3,5,7,0,0,0]
    */
    
    int insert_index = 0, row_i_real = 0, element_i_real = 0;
    for (int row_index = 0; row_index < matSize; ++row_index) {
        row_i_real = 0;
        element_i_real = row_index;
        for (int element_index = 0; element_index <= row_index; ++element_index) {
            ret_array[insert_index++] = mat[row_i_real][element_i_real];
            printf("row = %d, element %d; ", row_i_real, element_i_real);
            ++row_i_real;
            --element_i_real;
        }
        printf("\n");
    }
    
    // Iterate down
    /*
        1_2 2_1
        2_2
    */
    
    return ret_array;
}
