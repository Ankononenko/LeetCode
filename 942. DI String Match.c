int* diStringMatch(char * s, int* returnSize){
    short int len_s = strlen(s);
    short int start_d = len_s, start_i = 0;
    int* ints = (int*)malloc((len_s + 1) * sizeof(int));
    for (short int i = 0; i <= len_s; ++i) {
        if (i == len_s) {
            ints[i] = start_d;
            break;
        }
        if (s[i] == 'D') {
            ints[i] = start_d--;
        } else {
            ints[i] = start_i++;
        }
    }
    *returnSize = len_s + 1;
 return ints;
}
