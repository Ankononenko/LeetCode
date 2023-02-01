bool validMountainArray(int* arr, int arrSize){
    if (arrSize >= 3) {
        int p_index = 0, c_index = 1, is_going_up = 0, is_going_down = 0;
        if (c_index < arrSize && arr[c_index] > arr[p_index]) {
            is_going_up = 1;
        }
        while (c_index < arrSize && (arr[c_index] > arr[p_index])) {
                ++c_index;
                ++p_index;
            }
        if (c_index < arrSize && arr[c_index] < arr[p_index]) {
            is_going_down = 1;
        }
        while (c_index < arrSize && (arr[c_index] < arr[p_index])) {
                ++c_index;
                ++p_index;
            }
        if (p_index == arrSize - 1 && is_going_up && is_going_down) {
            return true;
        }
    }
    return false;
}
