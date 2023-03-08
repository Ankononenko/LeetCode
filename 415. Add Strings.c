char * addStrings(char * num1, char * num2){
    int num1_len = strlen(num1), num2_len = strlen(num2);
    int longest_len = (num1_len >= num2_len) ? num1_len : num2_len;
    // Allocate extra byte for remainder and null terminator
    char* res = (char*)malloc((longest_len + 2) * sizeof(char));
    int num1_read_i = num1_len - 1, num2_read_i = num2_len - 1;
    int res_insert_i = longest_len, remainder = 0, cur_res = 0;
    int num1_digit = 0, num2_digit = 0;
    for (int i = 0; i < longest_len; ++i) {
        num1_digit = (num1_read_i >= 0) ? (num1[num1_read_i] - '0') : 0;
        num2_digit = (num2_read_i >= 0) ? (num2[num2_read_i] - '0') : 0;
        cur_res = num1_digit + num2_digit + remainder;
        remainder = cur_res / 10;
        cur_res = cur_res % 10;
        res[res_insert_i] = cur_res + '0';
        --res_insert_i;
        --num1_read_i;
        --num2_read_i;
    }
    if (remainder > 0) {
        res[res_insert_i] = remainder + '0';
        --res_insert_i;
    }
    res[longest_len + 1] = '\0';
    // Return pointer to start of result string
    return res + res_insert_i + 1;
}
