class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            seen.insert(nums[i]);
        }

        int longest = 0;

        for (auto& n : seen) {
            if (!seen.count(n - 1)) {
                int curr_len = 1;
                while (seen.count(n + curr_len)) {
                    curr_len++;
                }
                longest = max(longest, curr_len); 
            }
        }
        return longest;
    }
};
