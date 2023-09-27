class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int i = 0, j = m - 1;
        int diff = INT_MAX;
        int a,b;
        while(i < n and j >= 0) {
            int total = arr[i] + brr[j];
            if(abs(total - x) < diff) {
                a = arr[i];
                b = brr[j];
                diff = abs(total - x);
            }
            else if(total > x) j--;
            else i++;
        }
        return {a,b};
    }
};