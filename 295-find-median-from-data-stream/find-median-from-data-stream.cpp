class MedianFinder {
public:
    priority_queue<int> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;

    MedianFinder() {}

    void addNum(int num) {
        if (pqMax.empty() || num >= pqMax.top()) {   //inserting into  queuq
            pqMin.push(num);
        } else {
            pqMax.push(num);
        }

        if (pqMin.size() > pqMax.size() + 1) {      //rebalancing both queue on each step to have median correct
            pqMax.push(pqMin.top());
            pqMin.pop();
        } else if (pqMax.size() > pqMin.size() + 1) {
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
    }

    double findMedian() {
        if (pqMin.size() > pqMax.size()) {             //for odd median
            return pqMin.top();
        } else if (pqMin.size() < pqMax.size()) {
            return pqMax.top();
        } else {
            return ((double)pqMin.top() + pqMax.top()) / 2;   //if both have even element means even and median will be (x+y)/2
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */