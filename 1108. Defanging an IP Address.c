char * defangIPaddr(char * address){
    char* result_ip;
    result_ip = (char*)malloc(22 * sizeof(char));
    char read_index = 0, write_index = 0;
    while (address[read_index]) {
        if(address[read_index] == '.') {
            result_ip[write_index++] = '[';
            result_ip[write_index++] = '.';
            result_ip[write_index++] = ']';
        } else {
            result_ip[write_index++] = address[read_index];
        }
        ++read_index;
    }
    result_ip[write_index] = '\0';
    return result_ip;
}
