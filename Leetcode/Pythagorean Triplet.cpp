class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    for(int i = 0; i<n; i++) arr[i] = arr[i] * arr[i];
        sort(arr,arr + n);
        for(int i = n - 1; i>=2; i--) {
            int l = 0, r = i - 1;
            while(l < r) {
                if(arr[l] + arr[r] < arr[i]) l++;
                else if(arr[l] + arr[r] > arr[i]) r--;
                else return true;
            }
        }
        return false;

	}
};