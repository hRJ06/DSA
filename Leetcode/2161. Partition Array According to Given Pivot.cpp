class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int less = 0;
            int equal = 0;
            for(auto &i : nums) {
                if(i < pivot) less++;
                else if(i == pivot) equal++;
            }
            int i = 0;
            int j = less;
            int k = less + equal;
            vector<int> ans(nums.size());
            for(auto &n : nums) {
                if(n < pivot) ans[i++] = n;
                else if(n > pivot) ans[k++] = n;
                else ans[j++] = n;
            }
            return ans;
        }
    };