class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int i : stones) {
            maxHeap.push(i);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            if (first >= second) {
                int diff = first - second;
                maxHeap.push(diff);
            }
        }

        if (maxHeap.empty()) {
            return 0;
        } else {
            return maxHeap.top();
        }
    }
};
