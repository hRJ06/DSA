class Solution
{
private:
    int f(int index,int n,string s,unordered_set<string> &st) {
        if(index >= n) return 1;
        string store = "";
        for(int i = index; i<n; i++) {
            store += s[i];
            if(st.find(store) != st.end()) {
                bool ans = f(i + 1,n,s,st);
                if(ans) return 1;
            }
        }
        return 0;
    }
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        return f(0,s.length(),s,st);
    }
};