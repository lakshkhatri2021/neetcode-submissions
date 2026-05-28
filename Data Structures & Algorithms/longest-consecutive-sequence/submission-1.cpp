class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> seen;
        for(int i = 0 ; i < nums.size(); i++){
            seen.insert(nums[i]);
        }
        int longest = 0;

        for(auto& i : seen){
            if(!seen.count(i-1)){
                int curr = 1;
                while(seen.count(i+curr)){
                    curr++;
                }
                longest = max(curr, longest);
            }
        }
        return longest;
    }
};
