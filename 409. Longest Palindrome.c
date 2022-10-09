void modify_array_letters(char* s, int* array_letters, int* i_index, int ascii_decimal);

int longestPalindrome(char * s){
    // Create an array for the letters (capital and lower-case)
    int array_size = 52;
    // Array of int is used for the values of chars that are greater than 127
    int array_letters[array_size];
    // Set a default values of "0"(int) to the values in the array
    memset(array_letters, 0, array_size * sizeof(int));

    // ASCII values of the letters capital (65 - 90) [%d - 65] and lower-case (97 - 122) [%d -  71] - I want for them to in row in the array of letters
    int i_index = 0, capital_ascii_dif = 65, lower_case_ascii_dif = 71;
    
    // While the s array hasn't ended, I check the values and write them to the temp array
    while (s[i_index]) {
        
        if (s[i_index] <= 90) {
            // %d - 65
            modify_array_letters(s, array_letters, &i_index, capital_ascii_dif);
        }
        
        if (s[i_index] > 90) {
            // %d - 71
            modify_array_letters(s, array_letters, &i_index, lower_case_ascii_dif);
        }
        
    }
    
    // num_uneven parameter is used to track the number of uneven values. If there are more than two, I increment
    int longest_palindrome = 0, num_uneven = 0;
    
    // Check the created array = number of %2 == 0 + 1 uneven = longest palindrome
    for (int j_index = 0; j_index < array_size; ++j_index) {
      
        // All even values are added to the longest palindrome value since from all of them we can build a palindrome
        if (array_letters[j_index] > 0 && array_letters[j_index] % 2 == 0) {
            longest_palindrome += array_letters[j_index];
        } 
        // All uneven values are added to the resulting array with decrement (that way they become even)
          else if (array_letters[j_index] % 2 == 1) {
            longest_palindrome += array_letters[j_index] - 1;
            if (num_uneven < 2) {
                ++num_uneven;
            }
        }
    }
    
    // Increment one covering the minus one in the uneven condition
    if (num_uneven) {
        ++longest_palindrome;
    }
    
    return longest_palindrome;
}

// Helping function used to modify the array usuing the ASCII values
void modify_array_letters(char* s, int* array_letters, int* i_index, int ascii_decimal) {
    int current_index = (int)s[*i_index];
    
    if (array_letters[current_index - ascii_decimal] == 0) {
        array_letters[current_index - ascii_decimal] = 1;
    } else {
        ++array_letters[current_index - ascii_decimal];
    }
    
    ++*i_index;
}
