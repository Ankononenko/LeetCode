// School 21 finchren
/*
✔ 1. Write a plan to complete the exercise
✔ 2. Iterate over a temp copy of the num and compare first to last to middle
✔ 3. Write tests - min, max, average values
✔ 4. Submit the solution
*/

void convert_to_array(int temp_x, int array[], int *array_len);
void init_array(int array[], const int size);
int is_negative(const int temp_x);
int check_if_palindrome(const int array[], const int array_len);

bool isPalindrome(int x){
    int is_palindrome = false;
    int temp_x = x;
    if (!is_negative(temp_x)) {
        if (temp_x <= 9 && temp_x >= 0) {
            is_palindrome = true;
        } else {
            int int_max_len = 10, array_len = 0;
            int array[int_max_len];
            init_array(array, int_max_len);
            convert_to_array(temp_x, array, &array_len);
            is_palindrome = check_if_palindrome(array, array_len);
        }
    }
    return is_palindrome;
}

int check_if_palindrome(const int array[], const int array_len) {
    int is_palindrome = true, index_min = 0, index_max = array_len - 1;
    while (is_palindrome && index_min != index_max && index_min >= 0 && index_max >= 0) {
        if (array[index_min] != array[index_max]) {
            is_palindrome = false;
        }
        ++index_min;
        --index_max;
    }
    return is_palindrome;
}

int is_negative(const int temp_x) {
    return temp_x < 0 ? true : false;
}

void init_array(int array[], const int size) {
    for (int index = 0; index < size; ++index) {
        array[index] = 0;
    }
}

void convert_to_array(int temp_x, int array[], int *array_len) {
    while (temp_x) {
        array[*array_len] = temp_x % 10;
        temp_x /= 10;
        ++*array_len;
    }
}
