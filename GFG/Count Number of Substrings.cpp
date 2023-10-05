typedef long long ll;
class Solution
{   
  private:
    int f(string s,int k) {
        vector<int> v(26,0);
        int dis = 0, left = 0, n = s.length();
        ll ans = 0;
        for(int i = 0; i<n; i++) {
            v[s[i] - 'a']++;
            if(v[s[i] - 'a'] == 1) dis++;
            while(dis > k) {
                v[s[left] - 'a']--;
                if(!v[s[left] - 'a']) dis--;
                left++;
            }
            ans += (i - left + 1);
        }   
        return ans;
    }
  public:
    long long int substrCount (string s, int k) {
    	return f(s,k) - f(s,k - 1);
    }
};