int titleToNumber(char * columnTitle){

    int output = 0, current_index = 0, max_len = strlen(columnTitle) - 1;
    int ascii_len = 64, alphabet_remainder = 27, alphabet_len = 26;
    char current_char = '\0';

    while (columnTitle[current_index]) {
        current_char = columnTitle[current_index++];
        output += ((current_char - ascii_len) % alphabet_remainder) * pow(alphabet_len, max_len--);
    }

    return output;

}
