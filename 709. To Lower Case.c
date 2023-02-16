char * toLowerCase(char * string){
    int index = 0, low_to_up_ascii_diff = 32, capital_ascii_start = 65, capital_ascii_end = 90;
    while (string[index]) {
        if (string[index] <= capital_ascii_end && string[index] >= capital_ascii_start) {
            string[index] |= low_to_up_ascii_diff;
        }
        ++index;
    }
    return string;
}
