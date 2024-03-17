class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        unordered_map<int,bool> mp;
        struct Node* t = head1;
        while(t) {
            mp[t->data]= true;
            t = t->next;
        }
        t = head2;
        int ans = 0;
        while(t) {
            if(mp.count(x - t->data)) ans++;
            t = t->next;
        }
        return ans;
    }
};