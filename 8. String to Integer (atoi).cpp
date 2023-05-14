class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        // Count the digits in the string
        int num_count = 0, first_num_index = 0;
        bool num_counted = false, first_num_found = false;
        while (s[index] && !num_counted) {
            if (isdigit(s[index])) {
                // Get the index of the first digit to get the correct sign
                if (!first_num_found) {
                    first_num_index = index;
                    first_num_found = true;
                }
                ++num_count;
            }
            // Count the number of digits only in the first number
            if (num_count && !isdigit(s[index])) {
                num_counted = true;
            }
            ++index;
        }
        // Get the sign by reading the char prior to the first digit
        bool is_negative = false;
        // Check if the sign index is gte 0 and only then read the sign
        if (first_num_index - 1 >= 0) {
            is_negative = s[first_num_index - 1] == '-' ? true : false;
        }
        int result = 0, pow_of_ten = num_count - 1;
        // Compose the resulting number
        while (num_count) {
            result += (s[first_num_index] - '0') * pow(10, pow_of_ten);
            ++first_num_index;
            --num_count;
            pow_of_ten = pow_of_ten ? --pow_of_ten : pow_of_ten;
        }
        // Add the sign
        if (is_negative) {
            result = -result;
        }
        return result;
    }
};
