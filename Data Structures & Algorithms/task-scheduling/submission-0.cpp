class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        queue<pair<int, int>> cooldown;
        unordered_map<char, int> freq;

        int time = 0;

        for (char task : tasks) {
            freq[task]++;
        }

        for (auto i : freq) {
            maxHeap.push(i.second);
        }

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;
            if (!cooldown.empty()) {
                if (cooldown.front().second <= time) {
                    maxHeap.push(cooldown.front().first);
                    cooldown.pop();
                }
            }

            if (!maxHeap.empty()) {
                int rem = maxHeap.top();
                maxHeap.pop();
                rem--;
                if (rem > 0) {
                    cooldown.push({rem, time + n + 1});
                }
            }
        }

        return time;
    }
};
