int mostWordsFound(char ** sentences, int sentencesSize){
    char max = 0, cur_max = 1, letter_i = 0;
    for (char sentence_i = 0; sentence_i < sentencesSize; ++sentence_i) {
        while (sentences[sentence_i][letter_i]) {
            if (sentences[sentence_i][letter_i] == ' ') {
                ++cur_max;
            }
            ++letter_i;
        }
        max = cur_max > max ? cur_max : max;
        cur_max = 1;
        letter_i = 0;
    }
    return (int) max;
}
