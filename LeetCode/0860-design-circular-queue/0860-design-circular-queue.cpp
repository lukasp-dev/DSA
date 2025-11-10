class MyCircularQueue {
private:
    int size;
    int rear;
    int front;
    int count;
    vector<int> q;

public:
    MyCircularQueue(int k) {
        this->size = k;
        this->rear = 0;
        this->front = 0;
        this->count = 0;
        this->q = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[rear] = value;
        rear = (rear + 1) % size;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1)%size;
        count--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[(rear - 1 + size)%size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return size == count;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */