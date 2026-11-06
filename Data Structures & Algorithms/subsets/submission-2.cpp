class Solution {
    vector<vector<int>> res;
    vector<int> curr;

   public:
    void dfs(int i, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs(i + 1, nums);
        curr.pop_back();

        dfs(i + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};
