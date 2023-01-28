void duplicateZeros(int* arr, int arrSize) {
    int copy_index = 0, original_index = 0;
    int *arr_copy = malloc(sizeof(int) * arrSize);
    memcpy(arr_copy, arr, sizeof(int) * arrSize);
    while (original_index < arrSize) {
        if (!(arr_copy[copy_index])) {
            arr[original_index] = 0;
            if (original_index < arrSize - 1) {
                arr[++original_index] = 0;
            }
        } else {
            arr[original_index] = arr_copy[copy_index];
        }
        ++copy_index;
        ++original_index;
    }
}
