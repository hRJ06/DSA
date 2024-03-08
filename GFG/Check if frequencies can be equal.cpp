class Solution{
private:
    bool f(vector<int> &v) {
        int n = -1;
        for(auto &i : v) {
            if(i > 0) {
                if(n == -1) n = i;
                else if(n != i) return false;
            }
        }
        return true;
    }
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> v(26, 0);
	    for(auto &i : s)
	        v[i - 'a']++;
	   if(f(v)) return true;
	   for(int i = 0; i<26; i++) {
	       if(v[i] > 0) {
	           v[i]--;
	           if(f(v)) return true;
	           v[i]++;
	       }
	   }
	   return false;
	}
};