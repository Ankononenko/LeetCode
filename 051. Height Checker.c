int heightChecker(int* heights, int heightsSize){
    
    int expected[heightsSize];
    memset(expected, 0, heightsSize * sizeof(int));
    int heights_copy[heightsSize];
    memcpy(heights_copy, heights, heightsSize * sizeof(int));
    
    int min = 0, min_index = 0, temp = 0;
    
    // Create a sorted array of heights to compare original to
    for (int index_i = 0; index_i < heightsSize; ++index_i) {
        min = heights_copy[index_i];
        min_index = index_i;
        for (int index_j = index_i + 1; index_j < heightsSize; ++index_j) {
            if (heights_copy[index_j] < min) {
                min = heights_copy[index_j];
                min_index = index_j;
            }
        }
        expected[index_i] = min;
        if (index_i != min_index) {
            temp = heights_copy[min_index];
            heights_copy[min_index] = heights_copy[index_i];
            heights_copy[index_i] = temp;
        }
    }

    int no_match_counter = 0;
    
    // Compare original to the sorted version
    for (int index = 0; index < heightsSize; ++index) {
        if(heights[index] != expected[index]) {
            ++no_match_counter;
        }
    }
    return no_match_counter;
}
