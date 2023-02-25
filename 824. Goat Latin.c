void do_maa(char* result, int* insert_index, char a_repeat_index);
void check_letter(char* sentence, int read_index, char* is_vowel, char* is_consonant);
void insert_chars(char* result, char first_letter, char* is_vowel, char* is_consonant, char a_repeat_index, int *insert_index);

char * toGoatLatin(char * sentence){
    char* result = (char*)malloc(3000 * sizeof(char)); 
    char a_repeat_index = 0, is_vowel = 0, is_consonant = 0, first_letter = 0;
    int insert_index = 0, read_index = 0;
    while (sentence[read_index]) {
    if (!read_index || sentence[read_index] == ' ') {
        ++a_repeat_index;
        if (sentence[read_index] == ' ') {
            insert_chars(result, first_letter, &is_vowel, &is_consonant, a_repeat_index, &insert_index);
            ++read_index;
        }
            check_letter(sentence, read_index, &is_vowel, &is_consonant);
        if (is_vowel) {
            result[insert_index++] = sentence[read_index];
        }
            first_letter = sentence[read_index];
            ++read_index;
        } else {
            result[insert_index++] = sentence[read_index++];
        }
    }
    ++a_repeat_index;
    insert_chars(result, first_letter, &is_vowel, &is_consonant, a_repeat_index, &insert_index);
    result[--insert_index] = '\0';
    return result;

}

void insert_chars(char* result, char first_letter, char* is_vowel, char* is_consonant, char a_repeat_index, int *insert_index) {
    if (*is_vowel) {
        do_maa(result, insert_index, a_repeat_index);
        *is_vowel = 0;
    }
    if (*is_consonant) {
        result[(*insert_index)++] = first_letter;
        do_maa(result, insert_index, a_repeat_index);
        *is_consonant = 0;
    }
}

void do_maa(char* result, int* insert_index, char a_repeat_index) {
    result[(*insert_index)++] = 'm';
    for (char index = 0; index < a_repeat_index; ++index) {
        result[(*insert_index)++] = 'a';
    }
    result[(*insert_index)++] = ' ';
}

void check_letter(char* sentence, int read_index, char* is_vowel, char* is_consonant) {
    if (sentence[read_index] == 'a'|| sentence[read_index] == 'A' ||
        sentence[read_index] == 'e' || sentence[read_index] == 'E' ||
        sentence[read_index] == 'i' || sentence[read_index] == 'I' ||
        sentence[read_index] == 'o' || sentence[read_index] == 'O' ||
        sentence[read_index] == 'u' || sentence[read_index] == 'U' ) {
            *is_vowel = 1;
    } else {
        *is_consonant = 1;
    }
}
