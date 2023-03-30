int subtractProductAndSum(int n){
    int sum = 0, product = 1;
    while (n) {
        char current_digit = n % 10;
        sum += current_digit;
        product *= current_digit;
        n /= 10;
    }
    return product - sum;
}
