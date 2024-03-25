class Solution{
private:
    vector<string> ans;
    void f(int z,int o,string s,int n) {
        if(s.length() >= n) {
            if(o >= z) ans.push_back(s);
            return;
        }
        if(z <= o) {
            f(z + 1,o,s + "0",n);
            f(z,o + 1,s + "1",n);
        }
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    f(0,0,"",n);
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};