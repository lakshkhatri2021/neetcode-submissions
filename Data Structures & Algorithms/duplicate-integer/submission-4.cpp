class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ptr = 0;
        int size = nums.size();
        while(ptr<size-1){
            if(nums[ptr]==nums[ptr+1])
                return true;
            ptr++;
        }
        return false;
        
    }
};