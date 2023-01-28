void shift_by_one(int *arr, int start_index, int arrSize);

void duplicateZeros(int* arr, int arrSize){
    for (int index = 0; index < arrSize - 1; ++index) {
        if (!(arr[index])) {
            shift_by_one(arr, index, arrSize);
            arr[++index] = 0;
        }
    }
}

void shift_by_one(int *arr, int start_index, int arrSize) {
    int arr_copy[arrSize];
    for (int index = start_index; index < arrSize; ++index) {
        arr_copy[index] = arr[index];
        
    }
    for (int index = start_index; index < arrSize - 1; ++index) {
        arr[index + 1] = arr_copy[index];
    }
}
