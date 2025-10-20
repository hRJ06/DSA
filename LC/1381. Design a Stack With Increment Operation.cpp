class CustomStack {
private:
    stack<int> s;
    int size;
    
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(s.size() < size) {
            s.push(x);
        }
    }
    
    int pop() {
        if(!s.empty()) {
            int top = s.top();
            s.pop();
            return top;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        stack<int> t;
        int n = s.size();
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        for(int i = 0; i<n; i++) {
            int top = t.top();
            t.pop();
            if(i < k) top += val;
            s.push(top);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
