bool checkIfExist(int* arr, int arrSize) {
    if (arrSize && arr) {
        for (int index_i = 0; index_i < arrSize; ++index_i) {
            for (int index_j = 0; index_j < arrSize; ++index_j) {
                if ((index_i != index_j) && ((arr[index_j] * 2) == arr[index_i])) {
                    return true;
                }
            }
        }
    }
    return false;
}
