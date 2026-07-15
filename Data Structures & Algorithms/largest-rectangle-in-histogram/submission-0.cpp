class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> bars;

        int maxArea = 0;

        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!bars.empty() && heights[i] < heights[bars.top()]) {
                int pop = bars.top();
                bars.pop();
                int height = heights[pop];
                int right = i;
                int left;
                if (bars.empty()) {
                    left = -1;
                } else {
                    left = bars.top();
                }
                int width = right - left - 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }

            bars.push(i);
        }

        return maxArea;
    }
};
