int canBeTypedWords(char * text, char * brokenLetters){
    short int words = 0, text_index = 0;
    char letters_index = 0, is_broken = 0;
    while (text[text_index]) {
        is_broken = 0;
        while (text[text_index] != ' ' && text[text_index] != '\0') {
            letters_index = 0;
            while (brokenLetters[letters_index] && !is_broken) {
                if (text[text_index] == brokenLetters[letters_index]) {
                    is_broken = 1;
                }
                ++letters_index;
            }
            ++text_index;
            if ((text[text_index] == ' ' || text[text_index] == '\0') && !is_broken) {
                ++words;
            }
        }
        if (text[text_index] == ' ') {
            ++text_index;
        }
    }
    return words;
}
