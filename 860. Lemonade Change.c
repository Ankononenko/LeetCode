// Problem - https://leetcode.com/problems/lemonade-change/

// Test-case generator:
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int array[3] = {5, 10, 20};

    printf("[");
    for (int i = 0; i <= 50000; ++i) {

        int random_index = 0, random_value = 0;

        random_index = rand() % 3;
        random_value = array[random_index];
    
        if (i < 50000) {
            printf("%d,", random_value);
        } else {
            printf("%d", random_value);
        }
    }
    printf("]");

    return 0;
}
*/

// Copyright 2022 School 21 finchren

bool lemonadeChange(int* bills, int billsSize){
    
    // Variables that are going to hold the number of bills
    // Twenties are not included since we cannot give change in twenties
    // So their amount doesn't matter to us
    int five_n = 0, ten_n = 0;
    bool can_be_changed = true;
    
    for (int i = 0; i < billsSize; ++i) {
        // If the input is 5 bill, add in to the counter
        // No change needs to be returned
        if (bills[i] == 5) {
            ++five_n;
        } 
        // If the bill is 10, give one change of 5 and add 10 to the counter
          else if (bills[i] == 10) {
            if (five_n) {
                --five_n;
                ++ten_n;
            } 
            // If there are no 5 bills, return false from the function
              else {
                can_be_changed = false;
                break;
            }
        } 
        // If the bill is 20 check if we have 10 and 5 bills 
          else {
            // If we do have them, give one 5 and 10
            if (ten_n && five_n) {
                --ten_n;
                --five_n;
            } 
            // If there are no 10, check how many 5s we have
            // If there are enough 5s to give change, decrease 5s
              else if (!ten_n && five_n >= 3) {
                five_n = five_n - 3;
            } 
            // If there are not enough 5s and no 10s, return false
              else {
                  can_be_changed = false;
            }
        }
    }
    
    return can_be_changed;
}
