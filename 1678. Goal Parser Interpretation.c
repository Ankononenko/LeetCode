char * interpret(char * command){
    int read_i = 0, insert_i = 0;
    while (command[read_i]) {
        if (command[read_i] == '(') {
            ++read_i;
            if (command[read_i] == ')') {
                command[insert_i++] = 'o';
                ++read_i;
            } else {
                command[insert_i++] = 'a';
                command[insert_i++] = 'l';
                read_i += 3;
            }
        } else {
            command[insert_i++] = 'G';
            ++read_i;
        }
    }
    command[insert_i] = '\0';
    return command;
}
