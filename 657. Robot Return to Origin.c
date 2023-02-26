bool judgeCircle(char * moves){
    
    int x = 0, y = 0, index = 0;
    bool is_back;
    
    while (moves[index]) {
        if (moves[index] == 'R') {
            ++x;
        }
        if (moves[index] == 'L') {
            --x;
        }
        if (moves[index] == 'U') {
            ++y;
        }
        if (moves[index] == 'D') {
            --y;
        }
        ++index;
    }

    is_back = !x && !y ? true : false;

    return is_back;

}
