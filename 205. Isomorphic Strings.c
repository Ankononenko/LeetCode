// Task - https://leetcode.com/problems/isomorphic-strings/

// Copyrigth 2022 School 21 finchren

bool isIsomorphic(char * s, char * t){
    // Used as final return value
    bool are_isomorphic = false;
    int index = 0;
    // Initialize an array of valid ascii chars
    // It's set in the conditions of the problem that s and t consist of only valid ascii chars
    // So save up memory and quicken the runtime of the program,
    // We are going to fill this array and look if there is already a char in the array
    char valid_ascii_chars_s[128] = {0};
    char valid_ascii_chars_t[128] = {0};
    // While chars exist, I iterate over the strings
    // Since the length is equal by the constraints of the task, I need to check only one
    while (s[index]) {
        // If the char hasn't been filled in yet, add it to the array
        // We add the chars to the array using their decimal value from the ascii table
        if (!valid_ascii_chars_s[s[index]] && !valid_ascii_chars_t[t[index]]){
            valid_ascii_chars_s[s[index]] = t[index];
            valid_ascii_chars_t[t[index]] = s[index];
        }
        // If the chars have been filled or one of them differs (s added to the array and t not and the other way around)
        // We check if it is already in the array and if not return false
        else {
            if (valid_ascii_chars_s[s[index]] != t[index] || valid_ascii_chars_t[t[index]] != s[index]) {
                return are_isomorphic;
            }
        }
        ++index;
        // If we reached the end of the both strings (each string in C ends with \0),
        // Then the strings are isomorphic since I checked the conditions above
        if (s[index] == '\0') {
            are_isomorphic = true;
        }
    }
    return are_isomorphic;
}
