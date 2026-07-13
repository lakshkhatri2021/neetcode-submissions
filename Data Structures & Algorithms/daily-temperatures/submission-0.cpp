class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> tempInd;
        vector<int> res(temps.size(), 0);

        for (int i = 0; i < temps.size(); i++) {
            while (!tempInd.empty() && temps[i] > temps[tempInd.top()]) {
                int idx = tempInd.top();
                tempInd.pop();
                res[idx] = i - idx;
            }
            tempInd.push(i);
        }

        return res;
    }
};
