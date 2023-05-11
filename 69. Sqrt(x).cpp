class Solution {
public:
    int mySqrt(int x) {
        double sqrt;
        if (x != 1) {
            sqrt = x / 2;
            double temp = 0;
            while (sqrt != temp) {
                temp = sqrt;
                sqrt = (x / temp + temp) / 2;
            }
        } else {
            sqrt = 1;
        }
        sqrt = std::floor(sqrt);
        return sqrt;
    }
};
