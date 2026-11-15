class Solution {
    vector<int> curr;
    vector<vector<int>> res;

   public:
    void dfs(int i, int target, vector<int>& nums) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (i == nums.size()) {
            return;
        }
        if(target < 0){
            return;
        }

        curr.push_back(nums[i]);
        dfs(i, target - nums[i], nums);
        curr.pop_back();
        dfs(i+1, target, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, target, nums);
        return res;
    }
};
