// User function Template for C++

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        // code here
        long long total = 0;
        for(int i = 0; i<N; i++) total += arr[i];
        return !(total % 3);
    }
};