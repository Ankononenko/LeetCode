bool isAnagram(char * s, char * t){
    bool is_anagram = true;
    if (strlen(t) != strlen(s)) {
        is_anagram = false;
    } else {
        unsigned short int letter_arr[26] = {0};
        unsigned short int index = 0;
        while (s[index]) {
            ++letter_arr[s[index++] - 'a'];
        }
        index = 0;
        while (t[index]) {
            --letter_arr[t[index++] - 'a'];
        }
        index = 0;
        for (; index < 26; ++index) {
            if (letter_arr[index] != 0) {
                is_anagram = false;
                break;
            }
        }
    }
    return is_anagram;
}
