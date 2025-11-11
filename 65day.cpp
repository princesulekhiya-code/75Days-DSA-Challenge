

class MedianFinder {
public:
    priority_queue<int> leftMax;
    priority_queue<int, vector<int>, greater<int>> rightMin;

    MedianFinder() {}

    void addNum(int num) {
        if (leftMax.empty() || num <= leftMax.top()) leftMax.push(num);
        else rightMin.push(num);

        if (leftMax.size() > rightMin.size() + 1) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        } else if (rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if (leftMax.size() == rightMin.size())
            return (leftMax.top() + rightMin.top()) / 2.0;
        return leftMax.top();
    }
};
