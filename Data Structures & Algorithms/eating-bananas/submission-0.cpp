class Solution {
   public:
    long long hoursNeeded(vector<int>& piles, int k) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + k - 1) / k;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hoursNeeded(piles, mid) <= h) {
                res = mid;
                high = mid - 1;
            } else if (hoursNeeded(piles, mid) > h) {
                low = mid + 1;
            }
        }
        return res;
    }
};