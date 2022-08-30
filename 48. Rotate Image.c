void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int k = *matrixColSize - 1;
    int temp = 0;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            temp = matrix[j][k];
            matrix[j][k] = matrix[i][j];
            matrix[i][j] = temp;
        }
        --k;
    }
}
