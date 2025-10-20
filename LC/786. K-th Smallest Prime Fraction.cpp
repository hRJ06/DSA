class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
        int n = arr.size();
        for(int i = 0; i<n; i++) 
            for(int j = i + 1; j<n; j++) 
                pq.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});
        pair<int, int> result;
        for(int i = 0; i<k; i++) {
            result = pq.top().second;
            pq.pop();
        }
        return {result.first, result.second};
    }
};
