class Solution{
  public:
    void swapElements(int arr[], int n){
        for(int i = 0; i + 2<n; i++) 
            swap(arr[i],arr[i + 2]);
        // Your code here
    }
};