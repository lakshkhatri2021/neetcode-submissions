class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size() - 1;
        while (first < last) {
            if (nums[first] + nums[last] > target) {
                last--;
            } else if (nums[first] + nums[last] < target) {
                first++;
            } else if (nums[first] + nums[last] == target) {
                return {first + 1, last + 1};
            }
        }
    }
};
