class MedianFinder {
public:
    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num<left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }

        int left = left_max_heap.size();
        int right = right_min_heap.size();

        if(left<right) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        } else if ((left-right) > 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }
    }
    
    double findMedian() {
        int n1 = left_max_heap.size();
        int n2 = right_min_heap.size();

        int n = n1 + n2;
        if(n%2 != 0) {
            return left_max_heap.top();
        } else {
            return (left_max_heap.top()+right_min_heap.top())/2.0;
        }
    }
};
