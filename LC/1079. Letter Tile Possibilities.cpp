class Solution {
    private:
        set<string> ans;
        void f(string &cur, string tiles, vector<bool> &v) {
            ans.insert(cur);
            for(int i = 0; i<tiles.length(); i++) {
                if(v[i]) continue;
                v[i] = true;
                cur.push_back(tiles[i]);
                f(cur, tiles, v);
                cur.pop_back();
                v[i] = false;
            }
        }
    public:
        int numTilePossibilities(string tiles) {
            int n = tiles.length();
            string cur = "";
            vector<bool> v(n, false);
            f(cur, tiles, v);
            return ans.size() - 1;
        }
    };