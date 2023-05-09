class Solution {
public:
    string defangIPaddr(string address) {
        string return_string;
        int index = 0;
        while(address[index]) {
            if (address[index] == '.') {
                return_string += "[";
                return_string += ".";
                return_string += "]";
            } else {
                return_string += address[index];
            }
            ++index;
        }
        return return_string;
    }
};
