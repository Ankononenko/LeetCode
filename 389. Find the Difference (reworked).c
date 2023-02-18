char findTheDifference(char * s, char * t){

    char return_char;

    if (s[0]) {

        short int low_letter_arr[26] = {0};
        short int index = 0;

        while (s[index]) {
            ++low_letter_arr[s[index] - 'a'];
            ++index;
        }

        index = 0;

        while (t[index]) {
            --low_letter_arr[t[index] - 'a'];
            if (low_letter_arr[t[index] - 'a'] < 0) {
                return_char = t[index];
                break;
            }
            ++index;
        }

    } else {
        return_char = t[0];
    }

    return return_char;
}
