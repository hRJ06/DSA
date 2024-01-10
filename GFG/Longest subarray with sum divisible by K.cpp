class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int> mp;
	    int total = 0, rem = 0, ans = 0;
	    for(int i = 0; i<n; i++) {
	        total += arr[i];
	        rem = total % k;
	        if(rem < 0) rem += k;
	        if(!rem) ans = max(ans,i + 1);
	        if(mp.count(rem)) {
	            ans = max(ans,i - mp[rem]);
	        }
	        else {
	            mp[rem] = i;
	        }
	    }
	    return ans;
	}
};