class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr + n,[&](Item A,Item B){
            double a = 1.0 * A.value / A.weight;
            double b = 1.0 * B.value / B.weight;
            return a > b;
        });
        double ans = 0;
        for(int i = 0; i<n; i++) {
            if(arr[i].weight <= W) {
                ans += arr[i].value;
                W -= arr[i].weight;
            }
            else {
                double add = 1.0 * arr[i].value / arr[i].weight;
                ans += add * W;
                break;
            }
        }
        return ans;
    }
        
};