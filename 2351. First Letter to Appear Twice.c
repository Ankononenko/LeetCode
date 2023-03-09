char repeatedCharacter(char * s){
    char i = 0, res;
    char chars[26] = {"\0"};
    while(s[i]) {
        chars[s[i] - 'a'] += 1;
        if (chars[s[i] - 'a'] > 1) {
            res = s[i];
            break;
        }
        ++i;
    }
    return res;
}
