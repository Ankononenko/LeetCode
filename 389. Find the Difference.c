int cmp(const void *a, const void *b);

char findTheDifference(char *s, char *t) {
    int i, n = strlen(s), m = strlen(t);
    char *ps = s, *pt = t;

    // Sort the strings
    qsort(s, n, sizeof(char), cmp);
    qsort(t, m, sizeof(char), cmp);

    // Compare the characters
    for (i = 0; i < n; i++) {
        if (*ps++ != *pt++) {
            return t[i];
        }
    }

    // If we get here, the last character in t is the difference
    return t[m-1];
}

int cmp(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}
