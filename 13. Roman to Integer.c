int romanToInt(char * s){
    short int roman_arr['X' + 1] = {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000
    };
    short int result = 0;
    for (short int index = 0; s[index]; ++index) {
        if (roman_arr[s[index]] < roman_arr[s[index + 1]]) {
            result -= roman_arr[s[index]];
        } else {
            result += roman_arr[s[index]];
        }
    }
    return result;
}
