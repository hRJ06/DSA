class Solution {
private:
    int f(vector<int> &arr, int K, int start, int n) {
        /* 
            K -> Need to find an element >= K in arr, BS will be starting from start 
        */
        int s = start, e = n - 1;
        int ans = -1;
        while(s <= e) {
            int m = s + (e - s) / 2;
            if(arr[m] >= K) {
                ans = m;
                e = m - 1;
            }
            else s = m + 1;
        }
        return ans;
    }
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        /* 
            We need to remove a single subarray 
            Either prefix / suffix / in between 
        */
        int n = arr.size();
        int prefix_index = 0, suffix_index = n - 1;
        for(int i = 1; i<n; i++) {
            if(arr[i] < arr[i - 1]) break;
            prefix_index = i;
        } 
        for(int i = n - 2; i>=0; i--) {
            if(arr[i] > arr[i + 1]) break;
            suffix_index = i;
        }
        if(!suffix_index or prefix_index >= n - 1) return 0;
        /* 1 2 3 10  -> 1 Prefix Index - 3*/ 
        /* 2 3 5 -> 2  Suffix Index = 5 */

        /* Can I do a binary Search for all the elements in the 1st array on the 2nd array */
        int ans = max(prefix_index + 1, n - suffix_index); 
        for(int i = prefix_index; i>=0; i--) {
            /* Find the index where it's first greater */
            int index = f(arr, arr[i], suffix_index, n);
            int length = i + 1 + (index != -1 ? n - index : 0);
            ans = max(ans, length);
        }
        return n - ans;
    }
};