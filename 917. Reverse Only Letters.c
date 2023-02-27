int is_letter(char cur_char);

char * reverseOnlyLetters(char * s){
    char start, end, temp;
    char start_i = 0, end_i = strlen(s) - 1;
    while (start_i < end_i) {
        if (!is_letter(s[start_i])) {
            ++start_i;   
        }
        if (!is_letter(s[end_i])) {
            --end_i;
        }
        if (is_letter(s[start_i]) && is_letter(s[end_i])) {
            temp = s[start_i];
            s[start_i] = s[end_i];
            s[end_i] = temp;
            ++start_i;
            --end_i;
        }
    }
    return s;
}

int is_letter(char cur_char) {
    return ((cur_char >= 65 && cur_char <= 90) || (cur_char >= 97 && cur_char <= 122));
}
