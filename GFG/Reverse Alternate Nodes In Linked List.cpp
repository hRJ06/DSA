class Solution
{
    private:
    Node* reverse(Node* head){
        Node* cur = head, *prev = NULL, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        Node* d = new Node(0);
        Node *cur = odd, *dhead = d, *tail = NULL;
        while(cur) {
            dhead->next = cur->next;
            dhead = dhead->next;
            if(cur->next) cur->next = cur->next->next;
            tail = cur;
            cur = cur->next;
        }
        tail->next = reverse(d->next);
    }
};
