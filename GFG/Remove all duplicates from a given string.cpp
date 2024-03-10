class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_set<char> s;
	    string ans = "";
	    for(auto &i : str) {
	        if(!s.count(i)) ans += i;
	        s.insert(i);
	    }
	    return ans;
	}
};