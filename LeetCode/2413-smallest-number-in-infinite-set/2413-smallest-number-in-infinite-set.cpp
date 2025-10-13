class SmallestInfiniteSet {
public:
    struct cmp {
        bool operator()(const int& a, const int& b)const{
            return a > b;
        }
    };

    priority_queue<int, vector<int>, cmp> pq;
    unordered_set<int> inHeap;
    int curr;

    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        int smallest = 0;
        if(pq.size()){
            smallest = pq.top();
            inHeap.erase(smallest);
            pq.pop();
        }else{
            smallest = curr;
            curr++;
        }

        return smallest;
    }
    
    void addBack(int num) {
        if(num < curr && inHeap.find(num) == inHeap.end()){
            pq.push(num);
            inHeap.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */