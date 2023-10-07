class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(!head or !head->next) return head;
        Node* store = head->next;
        head->next = pairWiseSwap(head->next->next);
        store->next = head;
        return store;
    }
};