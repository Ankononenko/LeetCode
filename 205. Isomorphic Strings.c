// Copyrigth 2022 School 21 finchren

bool isIsomorphic(char * s, char * t){
    // Used as final return value
    bool are_isomorphic = false;
    // I compare the previous and the next value of chars using these variables
    int chars_are_equal_s = 0, chars_are_equal_t = 0;
    char previous_s = '\0', previous_t = '\0';
    int index_upper = 0;
    // While chars exist, I iterate over the strings
    // Since the length is equal by the constraints of the task, I need to check only one
    while (s[index_upper]) {
        
        previous_s = s[index_upper];
        previous_t = t[index_upper];
        
        int index_inner = 0;
        while (s[index_inner]) {
            // If previous and next are equal, then 1, else 0
            chars_are_equal_s = previous_s == s[index_inner] ? 1 : 0;
            chars_are_equal_t = previous_t == t[index_inner] ? 1 : 0;
            // If the strings don't have the same squence of equal/unequal chars, I stop and return
            if (chars_are_equal_s != chars_are_equal_t) {
                return are_isomorphic;
            }
            // If the next chars exist, I increment the chars by one
            ++index_inner;   
        }
        
        ++index_upper;
        // If we reached the end of the both strings (each string in C ends with \0),
        // Then the strings are isomorphic since I checked the conditions above
        if (s[index_upper] == '\0') {
            are_isomorphic = true;
        }
        
    }
    return are_isomorphic;
}
