// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
   
    unsigned int current = 1, middle = 0;
    
    while (current < n) {
        
        middle = (current + n) / 2;
        
        if (isBadVersion(middle)) {
            n = middle;
        } else {
            current = middle + 1;
        }
    }
    
    return current;
}
