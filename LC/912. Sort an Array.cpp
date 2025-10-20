class Solution {
private:
    void merge(int s,int m,int e,vector<int> &nums) {
        int l1 = m - s + 1, l2 = e - m;
        vector<int> a(l1), b(l2);
        for(int i = 0; i<l1; i++)
            a[i] = nums[s + i];
        for(int i = 0; i<l2; i++) 
            b[i] = nums[m + 1 + i];
        int i = 0, j = 0, index = s;
        while(i < l1 and j < l2) {
            if(a[i] <= b[j])
                nums[index++] = a[i++];
            else 
                nums[index++]  = b[j++];
        }
        while(i < l1) 
            nums[index++] = a[i++];
        while(j < l2) 
            nums[index++] = b[j++];
    }
    void merge_sort(int s, int e, vector<int> &nums) {
        if(s >= e) return;
        int m = s + (e - s) / 2;
        merge_sort(s, m, nums);
        merge_sort(m + 1, e, nums);
        merge(s, m, e, nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        merge_sort(0, n - 1, nums);
        return nums;
    }
};
