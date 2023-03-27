int smallestEvenMultiple(int n){
    int res = n;
    while ((res % 2) || (res % n)) {
        res += n;
    } 
    return res;
}
