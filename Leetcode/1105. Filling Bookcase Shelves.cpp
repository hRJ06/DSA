class Solution {
private:
    int N, WIDTH;
    int t[1001][1001];
    int f(int index, vector<vector<int>> &books, int availableW, int maxH) {
        if(index >= N) return maxH;
        if(t[index][availableW] != -1) return t[index][availableW];
        int w = books[index][0];
        int h = books[index][1];
        int skip = INT_MAX, keep = INT_MAX;
        if(w <= availableW) {
            keep = f(index + 1, books, availableW - w, max(maxH, h));
        }
        skip = maxH + f(index + 1, books, WIDTH - w, h);
        return t[index][availableW] = min(skip, keep);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        N = n;
        WIDTH = shelfWidth;
        memset(t, -1, sizeof(t));
        return f(0, books, shelfWidth, 0);
    }
};
