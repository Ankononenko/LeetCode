/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int in_keyboard_row(char* word);

char ** findWords(char ** words, int wordsSize, int* returnSize){
    int result = 0, insert_index = 0;
    char **matching_words = (char **)malloc(wordsSize * sizeof(char *));

    for (int words_index = 0; words_index < wordsSize; ++words_index) {
        result = in_keyboard_row(words[words_index]);
        if (result) {
            matching_words[insert_index] = words[words_index];
            ++insert_index;
        }
    }

    *returnSize = insert_index;

    return matching_words;
}


int in_keyboard_row(char* word) {
    int in_the_row = 0;
    char max_row = 3, max_column = 11;
    char keyboard[3][11] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    int index_row = 0, index_column = 0, word_index = 0, matching_letters = 0;
    while (!in_the_row && index_row < max_row) {
        matching_letters = 0;
        word_index = 0;
        while (word[word_index]) {
            char lowercase_letter = tolower(word[word_index]);
            for (int letter_index = 0; letter_index < max_column; ++letter_index) {
                if (lowercase_letter == keyboard[index_row][letter_index]) {
                    ++matching_letters;
                    break;
                }
            }
            ++word_index;
            if (matching_letters == strlen(word)) {
                in_the_row = 1;
            }
        }
        ++index_row;
    }
    return in_the_row;
}
