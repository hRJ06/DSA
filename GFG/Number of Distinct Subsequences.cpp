typedef long long ll;
class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int MOD = 1e9 + 7;
	    int n = s.length();
	    vector<ll> arr(26,-1);
	    ll ans = 0;
	    for(int i = 0; i<n; i++) {
	        int index = s[i] - 'a';
	        if(!i) {
	            ans = 1;
	            arr[index] = 1;
	            continue;
	        }
	        ll add = 1 + ans;
	        if(arr[index] != -1) ans = (ans + add - arr[index]) % MOD;
	        else ans = (ans + add) % MOD;
	        arr[index] = add;
	    }
	    ans++;
	    return ans < 0 ? ans + MOD : ans;
	}
};