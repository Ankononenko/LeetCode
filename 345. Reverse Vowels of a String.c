int is_vowel(char character);
void find_start_i(int* start_i, int end_i, char* s);
void find_end_i(int* end_i, int start_i, char* s);

char * reverseVowels(char * s){
    int start_i = 0, end_i = strlen(s) - 1;
    char temp = '\0';
    while (start_i < end_i) {

        find_start_i(&start_i, end_i, s);
        find_end_i(&end_i, start_i, s);

        if (start_i <= end_i) {
            temp = s[start_i];
            s[start_i] = s[end_i];
            s[end_i] = temp;
        }
        
        ++start_i;
        --end_i;
    }
    return s;
}

void find_end_i(int* end_i, int start_i, char* s) {
    while (*end_i > start_i && !is_vowel(s[*end_i])) {
        --(*end_i);
    }
}

void find_start_i(int* start_i, int end_i, char* s) {
    while (*start_i < end_i && !is_vowel(s[*start_i])) {
        ++(*start_i);
    }
}

int is_vowel(char character) {
    if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U') {
        return 1;
    } else {
        return 0;
    }
}
