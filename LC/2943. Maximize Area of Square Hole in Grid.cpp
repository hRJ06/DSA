class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        int maxH = 1, curH = 1;
        int maxV = 1, curV = 1;
        for(int i = 1; i<hBars.size(); i++) {
            if(hBars[i] - hBars[i - 1] > 1) curH = 1;
            else curH++;
            maxH = max(maxH, curH);
        }
        for(int i = 1; i<vBars.size(); i++) {
            if(vBars[i] - vBars[i - 1] > 1) curV = 1;
            else curV++;
            maxV = max(maxV, curV);
        }
        int len = min(maxH, maxV) + 1;
        return len * len;
    }
};