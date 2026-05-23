class MedianFinder {
    // TC-  addNum O(log n). findMed O(1). SC O(n)
    priority_queue<int> left;//max heap left half small elements
    priority_queue<int,vector<int>,greater<int>> right;//min heap. right half. large elements
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //step 1 push in left half
        left.push(num);
        //step 2 move element from left to right half
        right.push(left.top());
        left.pop();
        //step 3 balance the queue
        if(left.size()<right.size()) {
            left.push(right.top());
        right.pop();
        }
        
    }
    
    double findMedian() {
        if(left.size()>right.size()) {
            return left.top();
        }
        return (left.top()+right.top())/2.0;
        
    }
};
