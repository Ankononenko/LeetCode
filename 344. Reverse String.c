void reverseString(char* s, int sSize){
    int s_index = 0, e_index = sSize - 1;
    char temp = '\0';
    while (s_index < e_index) {
        temp = s[s_index];
        s[s_index++] = s[e_index];
        s[e_index--] = temp;
    }
}
