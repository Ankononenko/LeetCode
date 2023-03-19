int minSteps(char * s, char * t){
    int str_len = strlen(s);
    int res = 0;
    int num_chars[26] = {0};
    for (int i = 0; i < str_len; ++i) {
        ++num_chars[s[i] - 'a'];
    }
    for (int i = 0; i < str_len; ++i) {
        --num_chars[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        res = num_chars[i] > 0 ? res + num_chars[i] : res;
    }
    return res;
}
