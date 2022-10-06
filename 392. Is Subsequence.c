// Link to the problem - https://leetcode.com/problems/is-subsequence/

bool isSubsequence(char * s, char * t){
    
    bool result = false;
    int index_s = 0, index_t = 0;
    
    // While there are chars in t array, I compare the values
    while (t[index_t]) {
        
        if (s[index_s] == t[index_t]) {
            ++index_s;
        }
        
        ++index_t;
    }

    // Find the lenght of the s array
    int size_s = 0;
    
    while (s[size_s]) {
        ++size_s;
    }
    
    // If we found all the values in the array s, then return true
    if (index_s == size_s) {
        result = true;
    }
    
    return result;
}
