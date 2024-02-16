class Solution{
    private:
    bool check(int i,int arr[]) {
        int left = arr[2 * i + 1];
        int right = arr[2 * i + 2];
        if(arr[i] >= left and arr[i] >= right) return true;
        return false;
    }
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i = n/2 - 1; i>=0; i--) {
            if(!check(i,arr)) return false;
        }
        return true;
    }
};