class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size_of_nums = nums.size(), target_been_found = 0;
        vector<int> result;
        for (int i = 0; i < size_of_nums; ++i) {
            for (int j = i + 1; j < size_of_nums; ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    target_been_found = 1;
                    break;
                }
            }
            if (target_been_found) {
                break;
            }
        }
        return result;
    }
};
