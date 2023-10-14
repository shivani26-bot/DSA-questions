class MedianFinder {
public:
priority_queue<int>maxHeap;
priority_queue<int,vector<int>,greater<int>>minHeap;
double currMedian;
void addToMaxHeap(int num){
    if(maxHeap.size()<=minHeap.size()) maxHeap.push(num);
    else{
        int x=maxHeap.top();
        maxHeap.pop();
        minHeap.push(x);
        maxHeap.push(num);
    }
}
void addToMinHeap(int num){
    if(maxHeap.size()>=minHeap.size()) minHeap.push(num);
    else{
        int x=minHeap.top();
        minHeap.pop();
        maxHeap.push(x);
        minHeap.push(num);
    }
}
void updateMedian(){
    if(maxHeap.size()==minHeap.size())
    currMedian=(maxHeap.top()+minHeap.top())/2.0;
    else if(minHeap.size()<maxHeap.size()) currMedian=maxHeap.top();
    else currMedian=minHeap.top();
}
    MedianFinder() {
        currMedian=0.0;
    }
    
    void addNum(int num) {
        if(num<=currMedian) addToMaxHeap(num);
        else addToMinHeap(num);

        updateMedian();
    }
    
    double findMedian() {
        return currMedian;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */