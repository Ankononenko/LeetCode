class Solution {
public:
    bool isPalindrome(int x) {
        bool is_palindrome = true;
        int x_len = std::to_string(x).length() / 2;
        string x_string = std::to_string(x);
        string x_reversed = x_string;
        std::reverse(x_reversed.begin(), x_reversed.end());
        int start_i = 0;
        while (start_i < x_len && is_palindrome) {
            if (x_string[start_i] != x_reversed[start_i++]) {
                is_palindrome = false;
            }
        }
        return is_palindrome;
    }
};
