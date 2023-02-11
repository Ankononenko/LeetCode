int find_len(char* string);
int are_all_ones(char* string, int start_index, int end_index);

char * addBinary(char * a, char * b){
    
    int a_len = (find_len(a));
    int b_len = (find_len(b));
    
    int new_arr_len = 0;

    // 1 for \0 at the end of the line;
    int extra_place = 1, diff = 0, all_ones = 0;
    if (a[0] == '1' && b[0] == '1') {
        if (a_len > b_len) {
            // +2 for extra char - remainder;
            all_ones = are_all_ones(a, b_len, a_len);
            // HERE
            extra_place = a[b_len] == '1' && all_ones ? 2 : 1;
        } else if (b_len > a_len) {
            all_ones = are_all_ones(b, a_len, b_len);
            // HERE
            extra_place = b[a_len] == '1' && all_ones ? 2 : 1;
        } else if (a_len == b_len) {
            extra_place = 2;
        }
    }

    int index_a = a_len - 1, index_b = b_len - 1;

    if (a_len > b_len || b_len > a_len) {
        new_arr_len = a_len > b_len ? a_len + extra_place: b_len + extra_place;
    } else {
        new_arr_len = a_len + extra_place;
    }

    char* ret_arr;
    ret_arr = (char*) malloc (new_arr_len * sizeof(char));

    printf("extra = %d, new_arr_len = %d\n", extra_place, new_arr_len);


    char remainder = '0', insert_char = '0';
    // HERE
    int insert_index = new_arr_len - extra_place;
    printf("insert_index = %d\n", insert_index);

    while (index_a >= 0 && index_b >= 0) {
        if (a[index_a] == '0' && b[index_b] == '0' && remainder == '0') {
            insert_char = '0';
        } else if (a[index_a] == '0' && b[index_b] == '0' && remainder == '1') {
            insert_char = '1';
            remainder = '0';
        } else if (a[index_a] == '1' && b[index_b] == '0' && remainder == '0') {
            insert_char = '1';
        } else if (a[index_a] == '0' && b[index_b] == '1' && remainder == '0') {
            insert_char = '1';
        } else if (a[index_a] == '1' && b[index_b] == '0' && remainder == '1') {
            insert_char = '0';
            remainder = '1';
        } else if (a[index_a] == '0' && b[index_b] == '1' && remainder == '1') {
            insert_char = '0';
            remainder = '1';
        } else if (a[index_a] == '1' && b[index_b] == '1' && remainder == '0') {
            insert_char = '0';
            remainder = '1';
        } else if (a[index_a] == '1' && b[index_b] == '1' && remainder == '1') {
            insert_char = '1';
            remainder = '1';
        }
        ret_arr[insert_index--] = insert_char;
        printf("a & b insert_char = %d\n", insert_char);
        --index_a;
        --index_b;
    }

    while (index_a >= 0) {
        if (a[index_a] == '1' && remainder == '1') {
            insert_char = '0';
            remainder = '1';
        } else if (a[index_a] == '0' && remainder == '1') {
            insert_char = '1';
            remainder = '0';
        } else if (a[index_a] == '1' && remainder == '0') {
            insert_char = '1';
        } else if (a[index_a] == '0' && remainder == '0') {
            insert_char = '0';
        }
        ret_arr[insert_index--] = insert_char;
        --index_a;
        printf("a insert_char = %d\n", insert_char);
    }

    while (index_b >= 0) {
        if (b[index_b] == '1' && remainder == '1') {
            insert_char = '0';
            remainder = '1';
        } else if (b[index_b] == '0' && remainder == '1') {
            insert_char = '1';
            remainder = '0';
        } else if (b[index_b] == '1' && remainder == '0') {
            insert_char = '1';
        } else if (b[index_b] == '0' && remainder == '0') {
            insert_char = '0';
        }
        ret_arr[insert_index--] = insert_char;
        printf("b insert_char = %d\n", insert_char);
        --index_b;
    }

    if (remainder == '1') {
        ret_arr[insert_index--] = remainder;
    }

    ret_arr[new_arr_len - 1] = '\0';
    
    return ret_arr;
}

int are_all_ones(char* string, int start_index, int end_index) {
    int all_ones = 1;
    for (int index = start_index; index < end_index; ++index) {
        if (string[index] != '1') {
            all_ones = 0;
            break;
        }
    }
    return all_ones;
}

int find_len(char* string) {
    
    int len = 0;
    
    while (string[len]) {
        ++len;
    }
    
    return len;
}
