int firstUniqChar(char * s){
    char sum = 0;
    int result = -1;
    for (int index_i = 0; s[index_i]; ++index_i) {
        for (int index_j = 0; s[index_j]; ++index_j) {
            sum = s[index_i] == s[index_j] ? ++sum : sum;
            if (sum == 2) {
                break;
            }
        }
        if (sum == 1) {
            result = index_i;
            break;
        }
        sum = 0;
    }
    return result;
}
