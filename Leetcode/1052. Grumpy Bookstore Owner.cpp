class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int free = 0, check = 0, n = customers.size(), greed = 0;
        for(int i = 0; i<n; i++) {
            if(!grumpy[i]) free += customers[i];
            else check += customers[i];
            if(i >= minutes and grumpy[i - minutes]) check -= customers[i - minutes];
            greed = max(greed,check);
        }
        return free + greed;
    }
};