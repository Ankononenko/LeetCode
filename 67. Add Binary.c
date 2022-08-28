// Copyright finchren School21 2022

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Find the maximum index of the array
int find_array_max_index(const char* array);

// Function to find the current element and look if we need to transfer a '1' to the next element
char find_current_element(const char a, const char b, char* next_element);

// Function to fill the lesser array with '0' until the size of the bigger array
void fill_lesser_array_with_zeros(char* array, const int lesser_array_max_index, const int bigger_array_max_index);

char* addBinary(char* a, char* b);

int main() {
    char a[5] = "1010";
    char b[5] = "1011";
    addBinary(a, b);
}

char* addBinary(char* a, char* b) {
    
    // Initialize the int values. Set them abnormal default values of -1, so it's easier to troubleshot, if something goes wrong in the function
    int arrays_min_index = -1, length_a_array = -1, length_b_array = -1;
    
    // Find the lenghts of the arrays so we would know until which point to sum
    length_a_array = find_array_max_index(a);
    length_b_array = find_array_max_index(b);
    
    // Find the max length between the arrays. This value is going to used to set the size of final array to be returned
    // If the lenght of the arrays is equal to each other, then this value is passed to the arrays_max_index
    const int arrays_max_index = length_a_array >= length_b_array ? length_a_array : length_b_array;
    arrays_min_index = length_a_array <= length_b_array ? length_a_array : length_b_array;

    // Initialize the resulting array size. It's going to depend on the first element of both the arrays
    // If they are both '1', then we need to add an extra index to store the extra '1'
    // Also add an extra index to store the endline '\0'
    int resulting_array_size = -1;
    if (a[0] == '1' && b[0] == '1') {
        resulting_array_size = arrays_max_index + 1 + 1;
    } else {
        resulting_array_size = arrays_max_index + 1;
    }
    
    // Initialize the resulting array to which we are going to write the resulting binary number
    // We add +1 to the lenght to work with the case where last elements are '1's and the result in tranferred to the next element
    // We fill the array with end of line elements, so even if no element is tranferred at the extra index, the programm doesn't get broken - 
    // The result isn't going to be read
    char *sum_result = malloc (sizeof (char) * (resulting_array_size));
    memset(sum_result, 0, (resulting_array_size) * sizeof(char));

    char temp_lesser_array[arrays_max_index];
    char temp_bigger_array[arrays_max_index];

    // Create a temp copy of the array of the lesser size. I'm going to fill it with '0' to fit to the max array size
    if (length_a_array > length_b_array || length_b_array > length_a_array) {


        char* lesser_array_pointer;
        if (length_a_array < length_b_array) {
            lesser_array_pointer = a;
        } else {
            lesser_array_pointer = b;
        }

        char* bigger_array_pointer;
        if (length_a_array > length_b_array) {
            bigger_array_pointer = a;
        } else {
            bigger_array_pointer = b;
        }

        for (int index = arrays_max_index; index <= 0; --index) {
            // Here I should copy the lesser array to the temp and fill the rest of the size with zero
            // I should fill it starting from the end. So the extra zero should be in the begging
            if (arrays_min_index >= 0) {
                temp_lesser_array[index] = lesser_array_pointer[arrays_min_index];
                --arrays_min_index;
            } else {
                temp_lesser_array[index] = '0';
            }
        }

        for (int index = arrays_max_index; index <= 0; --index) {
            // Here I should copy the lesser array to the temp and fill the rest of the size with zero
            // I should fill it starting from the end. So the extra zero should be in the begging
            temp_bigger_array[index] = bigger_array_pointer[index];
        }
    }
    
    // The next element is used to tranfer an extra '1' in case when we've added two '1's and write to the current index '0'
    char next_element = '0';
    
    // Index to be changed inside the for loop
    int elements_index = arrays_max_index;
    
    int temp_sum_result_index = resulting_array_size;
    sum_result[temp_sum_result_index] = '\0';
    --temp_sum_result_index;
    // For loop to iterate over each of elements of the arrays and add them to the resulting array
    for (int index = 0; index <= arrays_max_index; ++index) {
        sum_result[temp_sum_result_index] = find_current_element(temp_lesser_array[elements_index], temp_bigger_array[elements_index], &next_element);
        --elements_index;
        --temp_sum_result_index;
    }
    
    // If after iterating over the a and b arrays there is an extra '1', we add it to the resulting array
    if (next_element == '1') {
        sum_result[0] = '1';
    }
    
    // Print out the result for troubleshoting
    for (int i = 0; i <= resulting_array_size; ++i) {
        printf("%c", sum_result[i]);
    }
    return sum_result;
}

// Function to fill the lesser array with '0' until the size of the bigger array
void fill_lesser_array_with_zeros(char* array, const int lesser_array_max_index, const int bigger_array_max_index) {
    for (int index = lesser_array_max_index; index <= bigger_array_max_index; ++index) {
        array[index] = '0';
    }
}

// Function to find the current element and look if we need to transfer a '1' to the next element
char find_current_element(const char a, const char b, char* next_element) {
    
    // Variable to be returned from the function
    char current_element = '\0';
    
    // If '1' + '1' and next element equals to '0', current element equals '0' and '1' passed to next element
    if (a == '1' && b == '1' && *next_element == '0') {
        current_element = '0';
        *next_element = '1';
    }
    
    // If '1' + '1' and next element equals to '1', current element equals '1' and '1' passed to next element
    if (a == '1' && b == '1' && *next_element == '1') {
        current_element = '1';
        *next_element = '1';
    }
    
    // If a or b are equal to '0', and a or b equal to '1' and the next element equals to '0',
    // Then the current element is '1' and next is '0'
    if ((a == '0' || b == '0') && (a == '1' || b == '1') && *next_element == '0') {
        current_element = '1';
        *next_element = '0';
    }
    
    // If a or b are equal to '0', and a or b equal to '1' and the next element equals to '1',
    // Then the current element is '0' and next is '1'
    if ((a == '0' || b == '0') && (a == '1' || b == '1') && *next_element == '1') {
        current_element = '0';
        *next_element = '1';
    }
    
    // If a nad b are equal to '0' and the next element equals to '0',
    // Then the current element is '0' and next is '0'
    if (a == '0' && b == '0' && *next_element == '0') {
        current_element = '0';
        *next_element = '0';
    }
    
    // Final result being return from the function and the next element is being modified inside this function without return
    return current_element;
}

// Find the maximum index of the array
int find_array_max_index(const char* array) {

    int max_index = 0;
    
    while(array[max_index]) {
        ++max_index;
    }
    
    return max_index;
}
