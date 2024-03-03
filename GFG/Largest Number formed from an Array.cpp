class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    sort(arr.begin(),arr.end(),[&](string a,string b) { return a + b > b + a; });
	    string ans = "";
	    for(auto &i : arr) ans += i;
	    return ans;
	}
};