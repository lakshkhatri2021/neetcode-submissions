class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        while(left < right){
            if(height[left] < height[right]){
                maxLeft = max(height[left], maxLeft);
                res += maxLeft - height[left];
                left++;
            }
            else{
                maxRight = max(height[right], maxRight);
                res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};
