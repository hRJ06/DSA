class MyCalendarTwo {
private:
    vector<pair<int,int>> bookings, two_booking;
    bool overlap(int s1, int e1, int s2, int e2) {
        return max(s1, s2) < min(e1, e2);
    }
    pair<int,int> f(int s1, int e1, int s2, int e2) {
        return {max(s1, s2), min(e1, e2)};
    }
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int s1, int e1) {
        for(auto &i : two_booking) {
            int s2 = i.first, e2 = i.second;
            if(overlap(s1, e1, s2, e2)) {
                return false;
            }
        }
        for(auto &i : bookings) {
            int s2 = i.first, e2 = i.second;
            if(overlap(s1, e1, s2, e2)) {
                two_booking.push_back(f(s1, e1, s2, e2));
            }
        }
        bookings.push_back({s1, e1});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */