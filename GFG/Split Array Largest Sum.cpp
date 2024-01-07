class Solution {
  private:
    bool check(int arr[],int N,int MAX_SUM,int k) {
        int sum = 0, cuts = 0;
        for(int i = 0; i<N; i++) {
            if(sum + arr[i] > MAX_SUM) {
                cuts++;
                sum = arr[i];
            }
            else {
                sum += arr[i];
            }
        }
        return cuts < k;
    }
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int low = 0, high = 0;
        for(int i = 0; i<N; i++) {
            low = max(low,arr[i]);
            high += arr[i];
        }
        int ans = -1;
        while(low <= high) {
            int m = low + (high - low) / 2;
            if(check(arr,N,m,K)) {
                ans = m;
                high = m - 1;
            }
            else {
                low = m + 1;
            }
        }
        return ans;
    }
};