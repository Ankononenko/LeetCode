char is_at_least_one_char(char* word);
char get_char_word_len(char* word);
int string_to_int(char* word);

int maximumValue(char ** strs, int strsSize){
    int max = 0, cur_len = 0;
    for (char i = 0; i < strsSize; ++i) {
        if (is_at_least_one_char(strs[i])) {
            cur_len = get_char_word_len(strs[i]);
        } else {
            cur_len = string_to_int(strs[i]);
        }
        max = max < cur_len ? cur_len : max;
    }
    return max;
}

int string_to_int(char* word) {
    int res = 0;
    char i = 0, pow_of_ten = strlen(word) - 1;
    while (word[i]) {
        res += (word[i] - '0') * pow(10, pow_of_ten);
        --pow_of_ten;
        ++i;
    }
    return res;
}

char is_at_least_one_char(char* word) {
    char i = 0, is_char = 0;
    while (word[i] && !is_char) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            is_char = 1;
        }
        ++i;
    }
    return is_char;
}

char get_char_word_len(char* word) {
    return strlen(word);
}
