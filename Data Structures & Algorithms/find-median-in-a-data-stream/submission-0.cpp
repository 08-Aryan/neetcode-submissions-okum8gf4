class MedianFinder {
        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<int>> minheap;
        int minsz ,maxsz ;
public:
    MedianFinder() {
        minsz =0,maxsz = 0;
    }
    
    void addNum(int num) {
        maxheap.push(num);
        maxsz++;
        if(!minheap.empty() && maxheap.top() > minheap.top()){
            minheap.push(maxheap.top());
            maxheap.pop();
            maxsz--;
            minsz++;
        }
        if(maxsz - minsz > 1){
            minheap.push(maxheap.top());
            maxheap.pop();
            maxsz--;
            minsz++;
        }
        if(minsz - maxsz > 1){
            maxheap.push(minheap.top());
            minheap.pop();
            minsz--;
            maxsz++;
        }
    }
    
    double findMedian() {
        if(maxsz == minsz){
            return (maxheap.top()+minheap.top())/2.0;
        }
        if( maxsz > minsz){
            return maxheap.top()*1.0;
        }
        return minheap.top()*1.0;
    }
};
