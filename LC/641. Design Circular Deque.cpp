class MyCircularDeque {
private:
    vector<int> v;
    int size;
public:
    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value) {
        if(v.size() < size) {
            v.insert(v.begin(), value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(v.size() < size) {
            v.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(v.size()) {
            v.erase(v.begin());
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(v.size()) {
            v.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(v.size()) return v[0];
        return -1;
    }
    
    int getRear() {
        if(v.size()) return v[v.size() - 1];
        return -1;
    }
    
    bool isEmpty() {
        return v.empty();
    }
    
    bool isFull() {
        return v.size() >= size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */