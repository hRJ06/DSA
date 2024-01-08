class Solution
{
    private:
    struct Node* merge(struct Node* h1, struct Node* h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        if(h1->data < h2->data) {
            h1->next = merge(h1->next,h2);
            return h1;
        }
        else {
            h2->next = merge(h1,h2->next);
            return h2;   
        }
    }
    struct Node* reverse(struct Node* head) {
        struct Node* cur = head;
        struct Node* prev = NULL;
        struct Node* next = NULL;
        while(cur) {
            next = cur->next;
            cur ->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        struct Node* ans = merge(node1,node2);
        ans = reverse(ans);
        return ans;
    }  
};