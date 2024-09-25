class TrieNode {
public:
    int count = 0;
    TrieNode* children[26];
    TrieNode() {
        for(int i = 0; i<26; i++) {
            children[i] = NULL;
        }
    }
};
class Solution {
private:
    void insert(string word, TrieNode* root) {
        TrieNode* crawl = root;
        for(auto &i : word) {
            if(!crawl->children[i - 'a']) {
                crawl->children[i - 'a'] = new TrieNode();
            }
            crawl = crawl->children[i - 'a'];
            crawl->count += 1;
        }
    }
    int search(string word, TrieNode* root) {
        TrieNode* crawl = root;
        int ans = 0;
        for(auto &i : word) {
            ans += crawl->children[i - 'a']->count;
            crawl = crawl->children[i - 'a'];
        }
        return ans;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto &i : words) {
            insert(i, root);
        }
        vector<int> ans;
        for(auto &i : words) {
            ans.push_back(search(i, root));
        }
        return ans;
    }
};