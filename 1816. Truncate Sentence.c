char * truncateSentence(char * s, int k){
    short int index = 0;
    char spaces = 0;
    while (s[index]) {
        if (s[index] == ' ') {
            ++spaces;
        }
        if (spaces == k) {
            s[index] = '\0';
            break;
        }
        ++index;
    }
    return s;
}
