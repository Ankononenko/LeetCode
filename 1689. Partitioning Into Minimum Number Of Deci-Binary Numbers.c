int minPartitions(char * n){
    // Char type is used to save up the used memory
    char min = 0;
    while (*n) {
        // *n - '0' Represents the current char's int value
        min = *n - '0' < min ? min : *n - '0';
        ++n;
    }
    return (int)min;
}
