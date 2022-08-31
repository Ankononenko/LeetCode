bool isPalindrome(char * s){
    int n_chars = 0, is_palindrome = 0;
    while (*s) {
        if (*s >= 65 && *s <= 90) {
            *s = *s + 32;
            ++n_chars;
        } else if (*s >= 97 && *s <= 122) {
            *s = *s;
            ++n_chars;
        }
        ++s;
    }
    int j = n_chars / 2 + 1;
    int i = 0;
    while (s[i] == s[j] && i <= (n_chars / 2 + 1)) {
        --j;
        ++i;
        
    }
    if (i == (n_chars / 2 + 1) && j == 0) {
        is_palindrome = 1;
    }
    return is_palindrome;
}
