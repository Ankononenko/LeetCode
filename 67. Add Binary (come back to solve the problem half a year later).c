int find_len(char* string);
int are_all_ones(char* a, char* b, int a_len, int b_len);

char * addBinary(char * a, char * b){
    
    int a_len = (find_len(a));
    int b_len = (find_len(b));
    
    int new_arr_len = 0;

    // 1 for \0 at the end of the line;
    int extra_place = 1, diff = 0, all_ones = 0;
    if (a[0] == '1' && b[0] == '1') {
        if (a_len > b_len || b_len > a_len) {
            all_ones = are_all_ones(a, b, a_len, b_len);
            // +2 for extra char - remainder;
            extra_place = all_ones ? 2 : 1;
        } else if (a_len == b_len) {
            all_ones = 1;
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

    char remainder = '0', insert_char = '0';

    int insert_index = 0;
    if ((a_len > b_len || b_len > a_len) && !all_ones) {
        insert_index = new_arr_len - 1 - extra_place;
    } else if (a_len == 1 && b_len == 1 && !all_ones) {
        insert_index = 0;
    } else {
        insert_index = new_arr_len - extra_place;
    }

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
        --index_b;
    }

    if (remainder == '1') {
        ret_arr[insert_index--] = remainder;
    }

    ret_arr[new_arr_len - 1] = '\0';
    
    return ret_arr;
}

int are_all_ones(char* a, char* b, int a_len, int b_len) {
    int all_ones = 1, index_a = a_len - 1, index_b = b_len - 1;
    char remainder = '0';
    while (index_a >= 0 && index_b >= 0) {
        if (a[index_a] == '0' && b[index_b] == '0' && remainder == '1') {
            remainder = '0';
        } else if (a[index_a] == '1' && b[index_b] == '1' && remainder == '0') {
            remainder = '1';
        }
        --index_a;
        --index_b;
    }
    while (index_a >= 0) {
        if (a[index_a] == '0' && remainder == '1') {
            remainder = '0';
        }
        --index_a;
    }
    while (index_b >= 0) {
        if (b[index_b] == '0' && remainder == '1') {
            remainder = '0';
        }
        --index_b;
    }
    if (remainder == '1') {
        all_ones = 1;
    } else {
        all_ones = 0;
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
