int find_num_of_letters(int columnNumber);

char* convertToTitle(int columnNumber){
    
    int num_of_chars = find_num_of_letters(columnNumber);

    char* excel_title;
    excel_title = (char*)malloc((num_of_chars + 2) * sizeof(char));
    int insert_i = 0;

    int pow_of_26 = 0, division_res = 0;
    int alphabet_len = 26, ascii_start_i = 64;

    for (int pow_i = num_of_chars - 1; pow_i >= 0; --pow_i) {
        pow_of_26 = pow(alphabet_len, pow_i);
        division_res = columnNumber / pow_of_26;
        if (division_res) {
            columnNumber -= division_res * pow_of_26;
        } else {
            columnNumber -= columnNumber % pow_of_26;
        }
        excel_title[insert_i] = division_res + ascii_start_i;
        insert_i++;
    }

    excel_title[insert_i] = '\0';

    return excel_title;
}

int find_num_of_letters(int columnNumber) {

    int num_of_letters = 0, alphabet_len = 26;

    while (columnNumber > 0) {
        columnNumber -= 1;
        columnNumber /= alphabet_len;
        ++num_of_letters;
    }
    
    return num_of_letters;
}

