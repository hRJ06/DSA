class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = numBottles, ans = numBottles;
        while(numBottles >= numExchange) {
            int take = numBottles / numExchange;
            ans += take;
            numBottles = take + (numBottles % numExchange);
        } 
        return ans;
    }
};