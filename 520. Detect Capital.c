void check_capital(char* info, char* word, char is_first_capital_index, char are_all_capital_index, char any_except_first_capital_index);

bool detectCapitalUse(char* word){
    bool result;
    char info[3] = {'\0'};
    char is_first_capital_index = 0, are_all_capital_index = 1, any_except_first_capital_index = 2;
    check_capital(info, word, is_first_capital_index, are_all_capital_index, any_except_first_capital_index);
    if ((info[is_first_capital_index] && !info[any_except_first_capital_index])
      || info[are_all_capital_index]
      || !info[is_first_capital_index] && !info[any_except_first_capital_index]) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

void check_capital(char* info, char* word, char is_first_capital_index, char are_all_capital_index, char any_except_first_capital_index) {
    char index = 0, capital_counter = 0;
    if (word[index] >= 65 && word[index] <= 90) {
        info[is_first_capital_index] = 1;
        ++capital_counter;
    }
    ++index;
    while (word[index]) {
        if (word[index] >= 65 && word[index] <= 90) {
            ++capital_counter;
            info[any_except_first_capital_index] = 1;
        }
        ++index;
    }
    if (capital_counter == index) {
        info[are_all_capital_index] = 1;
    }
}
