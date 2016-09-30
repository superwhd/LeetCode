class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        return 0.5 * (minHeap.top() + maxHeap.top());
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
