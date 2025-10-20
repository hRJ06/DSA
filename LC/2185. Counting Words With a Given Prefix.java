class TrieNode {
    TrieNode[] children;
    boolean isEndOfWord;
    int count;
    TrieNode() {
        this.children = new TrieNode[26];
        this.isEndOfWord = false;
        this.count = 0;
        for(int i = 0; i<26; i++) {
            this.children[i] = null;
        }
    }
};

class Trie {
    TrieNode root;
    Trie() {
        root = new TrieNode();
    }
    void insert(String word) {
        TrieNode crawl = root;
        for(int i = 0; i<word.length(); i++) {
            int idx = word.charAt(i) - 'a';
            if(Objects.isNull(crawl.children[idx])) {
                crawl.children[idx] = new TrieNode();
            }
            crawl = crawl.children[idx];
            crawl.count++;
        }
        crawl.isEndOfWord = true;
    }
    int searchPrefix(String prefix) {
        TrieNode crawl = root;
        for(int i = 0; i<prefix.length(); i++) {
            int idx = prefix.charAt(i) - 'a';
            if(Objects.isNull(crawl.children[idx])) {
                return 0;
            }
            crawl = crawl.children[idx];
        }
        return crawl.count;
    }
};

class Solution {
    public int prefixCount(String[] words, String pref) {
        Trie trie = new Trie();
        int n = words.length;
        for(int i = 0; i<n; i++) {
            trie.insert(words[i]);
        }
        return trie.searchPrefix(pref);
    }
}