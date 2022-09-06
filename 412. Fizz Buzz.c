// Copyright 2022 School 21 finchren

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** fizzBuzz(int n, int* returnSize){
    // The returnSize value is used to find out the size of the resulting array that you are going to return from the function
    // Without it nothing is going to be returned from the function
    *returnSize = n;
    // Dynamically assign the two-dimensional array the size of n by char
    char **array_to_return = (char**)malloc(sizeof(char*) * (n));
    // We iterate from 1 till n and check each number for set conditions
    for (int i = 1; i <= n; ++i) {
        if (!(i % 3) && !(i % 5)) {
            // At the point where we've decided which element to add to the array,
            // We assign the size depending on the value that we want to copy to the resulting array
            // An extra index is for '\0'. It is the terminating symbol at the end of each string
            array_to_return[i - 1] = (char*)malloc(sizeof(char) * 9);
            // Function strcpy is part of string.h library
            // It copies to destination the target string
            strcpy(array_to_return[i - 1], "FizzBuzz");
        } else if (!(i % 3)) {
            array_to_return[i - 1] = (char*)malloc(sizeof(char) * 5);
            strcpy(array_to_return[i - 1], "Fizz");
        } else if (!(i % 5)) {
            array_to_return[i - 1] = (char*)malloc(sizeof(char) * 5);
            strcpy(array_to_return[i - 1], "Buzz");
        } else {
            array_to_return[i - 1] = (char*)malloc(sizeof(char) * 6);
            // sprtinf fucntion is used to copy the target string to destination
            // Depending on the type of copied value, a flag of that type of data is used
            // For example - %c for char, %s for string and etc
            sprintf(array_to_return[i - 1], "%d", i);
        }
    }
    return array_to_return;
}
