char * reverseWords(char * s){
    char temp[50000];
    int temp_index = 0, read_index = 0, insert_index = 0;
    while (s[read_index]) {
        while (s[read_index] != ' ' && s[read_index] != '\0') {
            temp[temp_index++] = s[read_index++];
        }
        --temp_index;
        for (; temp_index >= 0;) {
            s[insert_index++] = temp[temp_index--];
        }
        if (s[read_index] == ' ') {
            s[insert_index++] = ' ';
            ++read_index;
        }
        temp_index = 0;
    }
    return s;
}
