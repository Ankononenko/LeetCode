// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    unsigned int current = 1;
    
    // Until I find the bad version I multiply the current by 2
    while (!isBadVersion(current) && current <= n) {
        current *= 2;
    }
    
    // If the value is greater than max int, set current to max int
    if (current > INT_MAX) {
        current = INT_MAX;
    }
    
    unsigned int previous = current - 1;
    
    while (isBadVersion(previous / 2) && previous >= 1) {
        previous /= 2;
    }
    
    if (isBadVersion(previous) && isBadVersion(current)) {
        while (isBadVersion(previous) && isBadVersion(current)) {
            --previous;
            --current;
        } 
    }
    
    if (!isBadVersion(previous) && isBadVersion(current)) {
        while (!isBadVersion(previous) && isBadVersion(current)) {
            ++previous;
            --current;
        }
    }
        
    return ++current;
}
