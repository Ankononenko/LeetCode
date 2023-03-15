int are_words_equal(int start_i, int end_i, int start_j, int end_j, char* s);
int are_num_patters_equal_to_string(int pattern_len, char *s);
void get_word_start_end(int i, int *start, int *end, char *pattern, char *s);

bool wordPattern(char * pattern, char * s){
    int pattern_len = strlen(pattern);

    if (!are_num_patters_equal_to_string(pattern_len, s)) {
        return false;
    }

    for (int i = 0; i < pattern_len; ++i) {
        int s_start_i = 0, s_end_i = 0;
        get_word_start_end(i, &s_start_i, &s_end_i, pattern, s);

        for (int j = i + 1; j < pattern_len; ++j) {
            if (pattern[i] == pattern[j]) {
                int s_start_j = 0, s_end_j = 0;
                get_word_start_end(j, &s_start_j, &s_end_j, pattern, s);
                if (!are_words_equal(s_start_i, s_end_i, s_start_j, s_end_j, s)) {
                    return false;
                }
            } else {
                int s_start_j = 0, s_end_j = 0;
                get_word_start_end(j, &s_start_j, &s_end_j, pattern, s);
                if (are_words_equal(s_start_i, s_end_i, s_start_j, s_end_j, s)) {
                    return false;
                }
            }
        }
    }
    return true;
}


void get_word_start_end(int i, int *start, int *end, char *pattern, char *s) {
    int s_len = strlen(s);
    int num_spaces = 0;

    for (int k = 0; k < s_len; ++k) {
        if (num_spaces == i) {
            *start = k;
            while (k < s_len && s[k] != ' ') {
                k++;
            }
            *end = k - 1;
            break;
        }
        if (s[k] == ' ') {
            num_spaces++;
        }
    }
}

int are_num_patters_equal_to_string(int pattern_len, char *s) {
    int i = 0, space_counter = 1, are_equal = 0;
    while (s[i]) {
        if (s[i] == ' ') {
            ++space_counter;
        }
        ++i;
    }
    if (space_counter == pattern_len) {
        are_equal = 1;
    }
    return are_equal;
}

int are_words_equal(int start_i, int end_i, int start_j, int end_j, char* s) {
    if (end_i - start_i != end_j - start_j) {
        return 0;
    }

    while (start_i <= end_i && start_j <= end_j) {
        if (s[start_i] != s[start_j]) {
            return 0;
        }
        start_i++;
        start_j++;
    }
    return 1;
}

