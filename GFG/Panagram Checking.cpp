class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<int> v(26, 0);
        for(auto &i : s) {
            if(i >= 'A' and i <= 'Z') {
                v[i - 'A']++;
            }
            if(i >= 'a' and i <= 'z') {
               v[i - 'a']++;
            }
        }
        for(int i = 0; i<26; i++){
            if(!v[i]) return 0;
        }
        return 1;
    }
};