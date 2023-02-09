int check_if_all_nines(int* digits, int digitsSize);

int* plusOne(int* digits, int digitsSize, int* returnSize){

    // Case where the last digit isn't 9
    if (digits[digitsSize - 1] != 9) {
        ++digits[digitsSize - 1];
        *returnSize = digitsSize;
        return digits;
    } 

    // Case where all digits are 9s
    int are_all_nines = false;
    are_all_nines = check_if_all_nines(digits, digitsSize);
    if (are_all_nines) {
        *returnSize = are_all_nines == true ? digitsSize + 1 : digitsSize;
        int* return_array;
        return_array = (int*) malloc ((digitsSize + 1) * sizeof(int));
        memset(return_array, 0, *returnSize * sizeof(int));
        return_array[0] = 1;
        return return_array;
    }

    // Case where there is at least one 9 at the end of digits
    int last_digits_index = digitsSize - 1;
    int last_digit = digits[last_digits_index];
    while (last_digit == 9 && last_digits_index >= 1) {
        digits[last_digits_index] = 0;
        --last_digits_index;
        last_digit = digits[last_digits_index];
    }
    ++digits[last_digits_index];
    *returnSize = digitsSize;
    return digits;
}

int check_if_all_nines(int* digits, int digitsSize) {
    int all_nines = true, index = 0;
    while (all_nines && index < digitsSize) {
        if (digits[index] != 9) {
            all_nines = false;
        }
        ++index;
    }
    return all_nines;
}
