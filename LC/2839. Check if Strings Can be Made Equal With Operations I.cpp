class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 != s2) {
            string t1 = s1, t2 = s2;
            swap(s1[0], s1[2]);
            swap(t1[1], t1[3]);
            if((s1 != s2) and (t1 != t2)) {
                swap(s1[1], s1[3]);
                if(s1 != s2) return false;
                return true;
            }
            return true;
        }
        return true;
    }
};