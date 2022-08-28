int lengthOfLastWord(char * s){
// Last string length to be returned 
    int size_last_substring = 0;
// While s isn't NULL, to which '\0' also equals, we iterate
    while (*s) {

        if (*s != ' ') {
            ++size_last_substring;
        }
// If next element is another word and it is in the range of set string
// We start the count over
        if (*s == ' ' && *(s + 1) && *(s + 1) != ' ') {
            size_last_substring = 0;
        }

        ++s; 
    }
    return size_last_substring;
}
