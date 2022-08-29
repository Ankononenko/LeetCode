// https://leetcode.com/problems/climbing-stairs/

// Here we are going to use Fibonacci Sequence to find the sequence of steps for a staircase

int climbStairs(int n){
    int first = 0, second = 1, sum = 0, result = 0;
    
    for (int index = 1; index < n; ++index) {
        sum = first + second;
        first = second;
        second = sum;
    }
    
    result = first + second;
    
    return result;
}
