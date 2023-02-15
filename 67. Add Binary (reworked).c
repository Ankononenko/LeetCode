char *addBinary(char *a, char *b) {
    int a_len = strlen(a);
    int b_len = strlen(b);
    int max_len = fmax(a_len, b_len);
    char *result = (char *) malloc((max_len + 2) * sizeof(char));
    if (!result) {
        return NULL;
    }
    int carry = 0, i = 0;
    for (i = 0; i < max_len; i++) {
        int a_bit = i < a_len ? a[a_len - 1 - i] - '0' : 0;
        int b_bit = i < b_len ? b[b_len - 1 - i] - '0' : 0;
        int sum = a_bit + b_bit + carry;
        result[max_len - i] = sum % 2 + '0';
        carry = sum / 2;
    }
    if (carry) {
        result[0] = '1';
        result[max_len + 1] = '\0';
    } else {
        result++;
        result[max_len] = '\0';
    }
    return result;
}
