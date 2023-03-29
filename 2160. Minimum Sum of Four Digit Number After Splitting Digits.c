void int_to_str(char* digits, int num);
void sort(char* digits);
int count(char* digits);

int minimumSum(int num){
    char digits[4];
    int_to_str(&digits, num);
    sort(&digits);
    return count(digits);
}

int count(char* digits) {
    int first = digits[0] * 10 + digits[2];
    int second = digits[1] * 10 + digits[3];
    return first + second;
}

void sort(char* digits) {
    char temp, min, min_i;
    for (int i = 0; i < 4; ++i) {
        min = digits[i];
        min_i = i;
        for (int j = i + 1; j < 4; ++j) {
            if (digits[j] < min) {
                min = digits[j];
                min_i = j;
            }
        }
        if (min != digits[i]) {
            temp = digits[i];
            digits[i] = min;
            digits[min_i] = temp;
        }
    }
}

void int_to_str(char* digits, int num) {
    int insert_i = 0;
    while (num) {
        digits[insert_i++] = num % 10;
        num /= 10;
    }
}
