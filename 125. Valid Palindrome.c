bool isPalindrome(char * s){
    int n_chars = 0, index = 0;
    while (s[index]) {
        if (s[index] >= 65 && s[index] <= 90) {
            s[n_chars] = s[index] + 32;
            ++n_chars;
        } else if (s[index] >= 97 && s[index] <= 122) {
            s[n_chars] = s[index];
            ++n_chars;
        }
        ++index;
    }
    if (!n_chars || n_chars == 1) {
        return true;
    } else if (n_chars == 2) {
      if (s[0] == s[1]) {
          return true;
      }  
    } else {
        s[n_chars] = '\0';
        int j = n_chars - 1;
        int i = 0;
        while (s[i] == s[j] && i <= (n_chars / 2)) {
            --j;
            ++i;
            if (j == i) {
                return true;
            }
        }
    }
    return false;
}
