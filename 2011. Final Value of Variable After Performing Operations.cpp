class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;
        for (const auto& operation : operations) {
            if (operation.find('+') != std::string::npos) {
                ++count;
            } else if (operation.find('-') != std::string::npos) {
                --count;
            }
        }
        return count;
    }
};
