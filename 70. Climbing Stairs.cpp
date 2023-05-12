class Solution {
public:
    int climbStairs(int n) {
        int first = 0, second = 1, sum = 0;
        for (int index = 0; index < n; ++index) {
            sum = first + second;
            first = second;
            second = sum;
        }
        return sum;
    }
};
