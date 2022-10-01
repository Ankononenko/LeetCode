// Problem link - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

int numberOfSteps(int num){
    
    int number_of_steps = 0;
    
    while (num) {
        if (is_even(num)) {
            num /= 2;
        } else {
            num -= 1;
        }
        ++number_of_steps;
    }
    
    return number_of_steps;
}

int is_even(int num) {
    return num % 2 == 0 ? 1 : 0;
}
