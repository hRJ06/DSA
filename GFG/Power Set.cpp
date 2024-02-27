class Solution{
    private:
        void f(int index,string &s,string &store,vector<string> &ans) {
            if(index >= s.length()) {
                if(store != "")
                    ans.push_back(store);
                return;
            }
            store += s[index];
            f(index + 1,s,store,ans);
            store.pop_back();
            f(index + 1,s,store,ans);
        }
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string store = "";
		    f(0,s,store,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};