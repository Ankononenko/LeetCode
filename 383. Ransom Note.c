bool canConstruct(char * ransomNote, char * magazine){
    
    bool can_construct = true;
    int index_ransom_note = 0, length_of_ransom_note = 0, length_magazine = 0, num_occurrences = 0;
    
    length_of_ransom_note = find_len(ransomNote);
    length_magazine = find_len(magazine);
    
    while(ransomNote[index_ransom_note]) {
        
        bool current_char_in_magazine = false;
        int index_magazine = 0;
        
        while(magazine[index_magazine]) {
            
            if (ransomNote[index_ransom_note] == magazine[index_magazine]) {
                
                current_char_in_magazine = true;
                magazine[index_magazine] -= 32;
                ++num_occurrences;
                break;
                
                if (num_occurrences == length_of_ransom_note + 1) {
                    return true;
                }
                    
            }
            
            if (!current_char_in_magazine && index_magazine == length_magazine) {
                return false;
            }
            
            ++index_magazine;
            
        }
        
        ++index_ransom_note;
        
    }
    
    return can_construct;
}

int find_len(char* string) {
    int length = 0;
    
    while(string[length]) {
        ++length;
    }
    
    return length - 1;
}
