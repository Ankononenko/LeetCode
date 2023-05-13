class Solution {
    
public:

    std::unordered_map<char, int> roman_map;
    Solution() {
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;
    }

    int romanToInt(string s) {

        int result = 0, max_i_roman = s.size() - 1;
        int previous_i = max_i_roman;
 
        while (max_i_roman >= 0) {
            
            if (max_i_roman != s.size() - 1) {
                previous_i = max_i_roman + 1;
            }

            if (s[max_i_roman] == 'I' && !is_gt_previous(s, 'I', previous_i, max_i_roman)) {
                ++result;
            } else if (s[max_i_roman] == 'I' && is_gt_previous(s, 'I', previous_i, max_i_roman)) {
                --result;
            } else if (s[max_i_roman] == 'V' && !is_gt_previous(s, 'V', previous_i, max_i_roman)) {
                result += 5;
            } else if (s[max_i_roman] == 'V' && is_gt_previous(s, 'V', previous_i, max_i_roman)) {
                result -= 5;
            } else if (s[max_i_roman] == 'X' && !is_gt_previous(s, 'X', previous_i, max_i_roman)) {
                result += 10;
            } else if (s[max_i_roman] == 'X' && is_gt_previous(s, 'X', previous_i, max_i_roman)) {
                result -= 10;
            } else if (s[max_i_roman] == 'L' && !is_gt_previous(s, 'L', previous_i, max_i_roman)) {
                result += 50;
            } else if (s[max_i_roman] == 'L' && is_gt_previous(s, 'L', previous_i, max_i_roman)) {
                result -= 50;
            } else if (s[max_i_roman] == 'C' && !is_gt_previous(s, 'C', previous_i, max_i_roman)) {
                result += 100;
            } else if (s[max_i_roman] == 'C' && is_gt_previous(s, 'C', previous_i, max_i_roman)) {
                result -= 100;
            } else if (s[max_i_roman] == 'D' && !is_gt_previous(s, 'D', previous_i, max_i_roman)) {
                result += 500;
            } else if (s[max_i_roman] == 'D' && is_gt_previous(s, 'D', previous_i, max_i_roman)) {
                result -= 500;
            } else if (s[max_i_roman] == 'M' && !is_gt_previous(s, 'M', previous_i, max_i_roman)) {
                result += 1000;
            } else if (s[max_i_roman] == 'M' && is_gt_previous(s, 'M', previous_i, max_i_roman)) {
                result -= 1000;
            }

            --max_i_roman;
        }
        return result;
    }

    bool is_gt_previous(string s, char roman, int previous_i, int max_i_roman) {

        bool is_greater = false;
        
        if (s[max_i_roman] == roman && roman_map.at(s[previous_i]) > roman_map.at(s[max_i_roman])) {
            is_greater = true;
        }
        
        return is_greater;
    }

};
