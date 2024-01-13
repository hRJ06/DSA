class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        function<void(Node*)> f = [&](Node* head) {
            if(!head) return;
            f(head->next);
            int key = head->data;
            Node* next = head->next;
            while(next) {
                if(next->data < key) {
                    head->data = next->data;
                    head = next;
                    next = head->next;
                }
                else
                    break;
            }
            head->data = key;
        };
        f(head_ref);
        return head_ref;
    }
    
};