class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int>res;
        int left = 0, right = 0;
        for (right = 0; right < nums.size(); right++) {
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);
            if (dq.front() < right - k + 1) {
                dq.pop_front();
            }
            if(right >= k -1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
