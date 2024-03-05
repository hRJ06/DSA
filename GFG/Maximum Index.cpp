class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int> preMin(n,0), sufMax(n,0);
        int mx = a[n - 1];
        for(int i = n - 1; i>=0; i--) {
            mx = max(mx,a[i]);
            sufMax[i] = mx;
        }
        int mi = a[0];
        for(int i = 0; i<n; i++) {
            mi = min(mi,a[i]);
            preMin[i] = mi;
        }
        int i = 0, j = 0, ans = -1;
        while(i < n and j < n) {
            if(preMin[i] <= sufMax[j]) {
                ans = max(ans, j - i);
                j++;
            }
            else {
                i++;
            }
        }
        return ans;
    }
};