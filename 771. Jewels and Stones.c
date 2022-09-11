// Problem - https://leetcode.com/problems/jewels-and-stones/submissions/
// Copyright 2022 School 21 finchren

int numJewelsInStones(char * jewels, char * stones){
    int result = 0, index_s = 0, index_j = 0;
    while (stones[index_s]) {
        while (jewels[index_j]) {
            char stone = stones[index_s];
            char jewel = jewels[index_j];
            if (stone == jewel) {
                ++result;
            }
            ++index_j;
        }
        index_j = 0;
        ++index_s;
    }
    return result;
}
