class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
        vector<int> v;
        Node* t = (*head);
        while(t) {
            v.push_back(t->data);
            t = t->next;
        }
        std::sort(v.begin(),v.end());
        t = (*head);
        int n = v.size();
        for(int i = 0; i<n; i++, t = t->next)
            t->data = v[i];
    }
};