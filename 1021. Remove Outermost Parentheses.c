char * removeOuterParentheses(char * s){
    char* ret_arr = (char*)malloc(strlen(s) * sizeof(char));


    int insert_i = 0, read_i = 0, open_braces = 0, closed_braces = 0;
    int start_index = -1, end_index = -1;

    while (s[read_i]) {
        if (s[read_i] == '(') {
            ++open_braces;
            if (start_index == -1) {
                start_index = read_i;
            }
        }
        if (s[read_i] == ')') {
            ++closed_braces;
            end_index = read_i;
        }

        ++read_i;

        if (open_braces == closed_braces && open_braces != 0) {
            for (int i = start_index + 1; i < end_index; i++) {
                ret_arr[insert_i++] = s[i];
            }
            open_braces = 0;
            closed_braces = 0;
            start_index = -1;
            end_index = -1;
        }
    }

    ret_arr[insert_i] = '\0';
    return ret_arr;
}
