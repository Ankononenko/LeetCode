class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size(), index = 0;
        bool single_num_found = false;
        while (index < len && !single_num_found) {
            single_num_found = std::count(nums.begin(), nums.end(), nums[index]) == 1 ? true : false;
            ++index;
        }
        return nums[index - 1];
    }
};
