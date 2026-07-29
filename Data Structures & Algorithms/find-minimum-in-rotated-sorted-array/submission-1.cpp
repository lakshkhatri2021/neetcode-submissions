class Solution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int last = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[last]) {
                high = mid;
            } else if (nums[mid] > nums[last]) {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};
