char * replaceDigits(char * s){
    int index = 0;
    while (s[index]) {
        if (index % 2) {
            s[index] = s[index - 1] + (s[index] - 48);
        }
        ++index;
    }
    return s;
}
