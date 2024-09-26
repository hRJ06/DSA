class MyCalendar {
private:
    vector<pair<int,int>> v;
public:
    MyCalendar() {
        
    }
    
    bool book(int s1, int e1) {
        for(auto &i : v) {
            int s2 = i.first, e2 = i.second;
            if(!(s1 >= e2 or s2 >= e1)) {
                return false;
            }
        }
        v.push_back({s1, e1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */