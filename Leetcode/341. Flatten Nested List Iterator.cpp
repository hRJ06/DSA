class NestedIterator {
private:    
    vector<int> ans;
    int i;
public:
    void f(vector<NestedInteger> &nestedList) {
        for(int i = 0; i<nestedList.size(); i++) {
            if(nestedList[i].isInteger()) ans.push_back(nestedList[i].getInteger());
            else f(nestedList[i].getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        i = 0;
        f(nestedList);
    }
    
    int next() {
        return i < ans.size() ? ans[i++] : -1;
    }
    
    bool hasNext() {
        return i < ans.size();
    }
};
