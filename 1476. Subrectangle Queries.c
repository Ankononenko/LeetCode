/**
 * Your SubrectangleQueries struct will be instantiated and called as such:
 * SubrectangleQueries* obj = subrectangleQueriesCreate(rectangle, rectangleSize, rectangleColSize);
 * subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);
 
 * int param_2 = subrectangleQueriesGetValue(obj, row, col);
 
 * subrectangleQueriesFree(obj);
*/

typedef struct {
    int** rectangle;
    int row;
    int col;
} SubrectangleQueries;

SubrectangleQueries* subrectangleQueriesCreate(int** rectangle, int rectangleSize, int* rectangleColSize) {
    SubrectangleQueries* ret_rectangle = (SubrectangleQueries*) malloc(sizeof(SubrectangleQueries));
    ret_rectangle->rectangle = (int**)malloc(rectangleSize * sizeof(int*));
    for (int i = 0; i < rectangleSize; ++i) {
        ret_rectangle->rectangle[i] = (int*)malloc(rectangleColSize[i] * sizeof(int));
        memcpy(ret_rectangle->rectangle[i], rectangle[i], rectangleColSize[i] * sizeof(int));
    }
    ret_rectangle->row = rectangleSize;
    ret_rectangle->col = *rectangleColSize;
    return ret_rectangle;
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries* obj, int row1, int col1, int row2, int col2, int newValue) {
    for (int i = 0; i < obj->row; ++i) {
        for (int j = 0; j < obj->col; ++j) {
            if (i >= row1 && i <= row2 && j >= col1 && j <= col2) {
                obj->rectangle[i][j] = newValue;
            }
        }
    }
}

int subrectangleQueriesGetValue(SubrectangleQueries* obj, int row, int col) {
  return obj->rectangle[row][col];
}

void subrectangleQueriesFree(SubrectangleQueries* obj) {
    for (int i = 0; i < obj->row; ++i) {
        free(obj->rectangle[i]);
        obj->rectangle[i] = NULL;
    }
    free(obj->rectangle);
    obj->rectangle = NULL;
    obj->row = 0;
    obj->col = 0;
}
