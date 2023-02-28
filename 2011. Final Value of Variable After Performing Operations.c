int finalValueAfterOperations(char ** operations, int operationsSize){
    int final_value = 0;
    for (char word_i = 0; word_i < operationsSize; ++word_i) {
        if (operations[word_i][0] == 43 || operations[word_i][2] == 43) {
            ++final_value;
        } else {
            --final_value;
        }
    }
    return final_value;
}
