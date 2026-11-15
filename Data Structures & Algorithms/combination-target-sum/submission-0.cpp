class Solution {
    vector<int> curr;
    vector<vector<int>> res;

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, nums, target);
        return res;
    }

    void dfs(int i, vector<int>& nums, int target) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (i == nums.size()) {
            return;
        }

        if (target < 0) {
            return;
        }

        curr.push_back(nums[i]);
        dfs(i, nums, target - nums[i]);
        curr.pop_back();
        dfs(i + 1, nums, target);
    }
};
