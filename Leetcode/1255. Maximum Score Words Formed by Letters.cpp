class Solution {
private:
    void f(int i,int score,vector<int> &scores,vector<string> &words,int n,int &ans, vector<int> &freq) {
        if(i >= n) {
            ans = max(ans,score);
            return;
        }
        int j = 0, word_score = 0;
        vector<int> store = freq;
        while(j < words[i].length()) {
            char ch = words[i][j];
            store[ch - 'a']--;
            if(store[ch - 'a'] < 0) break;
            word_score += scores[ch - 'a'];
            j++;
        }
        if(j >= words[i].length())
            f(i + 1,score + word_score,scores,words,n,ans,store);
        f(i + 1,score,scores,words,n,ans,freq);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ans = INT_MIN, n = words.size();
        vector<int> freq(26, 0);
        for(auto &i : letters) {
            freq[i - 'a']++;
        }
        f(0,0,score,words,n,ans,freq);
        return ans;
    }
};