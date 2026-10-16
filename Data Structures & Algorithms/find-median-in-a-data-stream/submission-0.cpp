class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

   public:
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);
        int temp = small.top();
        small.pop();
        large.push(temp);

        if (large.size() > small.size()) {
            int temp = large.top();
            large.pop();
            small.push(temp);
        }
    }

    double findMedian() {
        double median;

        if (small.size() > large.size()) {
            median = small.top();
        }

        else {
            int smallBiggest = small.top();
            int largeSmallest = large.top();
            median = (smallBiggest + largeSmallest) / 2.0;
        }

        return median;
    }
};
