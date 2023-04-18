char *mergeAlternately(char *word1, char *word2) {
    int result_len = strlen(word1) + strlen(word2) + 1;
    char *res = (char *)malloc(result_len * sizeof(char));
    int i1 = 0, i2 = 0, insert_i = 0;

    while (word1[i1] || word2[i2]) {
        if (word1[i1]) {
            res[insert_i++] = word1[i1++];
        }
        if (word2[i2]) {
            res[insert_i++] = word2[i2++];
        }
    }
    res[insert_i] = '\0';
    return res;
}
