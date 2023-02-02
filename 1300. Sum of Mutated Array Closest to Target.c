int* replaceElements(int* arr, int arrSize, int* returnSize){
    int max = 0, max_index_to_store = 0;
    for (int index = 0; index < arrSize; ++index) {
        if (index != arrSize - 1) {
            // New max element is found only if the current element has passed the previously found max element
            if (index >= max_index_to_store) {
                max = arr[index + 1];
                for (int index_max = index + 1; index_max < arrSize; ++index_max) {
                    if (arr[index_max] > max) {
                        max = arr[index_max];
                        max_index_to_store = index_max;
                    }
                }
            }
            arr[index] = max;
        } else {
          arr[index] = -1;   
        }  
    }
    *returnSize = arrSize;
    return arr;
}
