class Solution{
private:
    void f(stack<int> &st,int x) {
        if(st.empty()) {
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        f(st,x);
        st.push(top);
    }
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        f(st,x);
        return st;
    }
};