int vowelStrings(char ** words, int wordsSize, int left, int right){
    int num_vowel_s = 0, last_i = 0;
    for (int i = left; i <= right; ++i) {
        last_i = strlen(words[i]) - 1;
        num_vowel_s = (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') &&
        (words[i][last_i] == 'a' || words[i][last_i] == 'e' || words[i][last_i] == 'i' || words[i][last_i] == 'o' || words[i][last_i] == 'u') ? ++num_vowel_s : num_vowel_s;
    }
    return num_vowel_s;
}
