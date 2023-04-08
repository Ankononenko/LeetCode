int check_current_elem(int** grid, int row_i, int col_i, int gridSize, int gridColSize);

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    for (int row_i = 0; row_i < gridSize; ++row_i) {
        for (int col_i = 0; col_i < *gridColSize; ++col_i) {
            res += check_current_elem(grid, row_i, col_i, gridSize, *gridColSize) - grid[row_i][col_i];
        }
    }
    return res;
}

int check_current_elem(int** grid, int row_i, int col_i, int gridSize, int gridColSize) {
    int under_skyline_diff = 0;
    // Go over the current row
    int row_diff = 0;
    for (int i = 0; i < gridSize; ++i) {
        row_diff = row_diff < grid[row_i][i] ? grid[row_i][i] : row_diff;
    }
    // Go over the current column
    int col_diff = 0;
    for (int i = 0; i < gridColSize; ++i) {
        col_diff = col_diff < grid[i][col_i] ? grid[i][col_i] : col_diff;
    }
    under_skyline_diff = row_diff < col_diff ? row_diff : col_diff;
    return under_skyline_diff;
}
