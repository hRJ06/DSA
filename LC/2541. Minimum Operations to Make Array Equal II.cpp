typedef long long ll;
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(!k) {
            if(nums1 != nums2) return -1;
            return 0;
        }   
        ll inc = 0, dec = 0;
        int n = nums1.size();
        for(int i = 0; i<n; i++) {
            if(nums1[i] != nums2[i]) {
                if(nums1[i] >= nums2[i]) {
                    if((nums1[i] - nums2[i]) % k) return -1;
                    else dec += (nums1[i] - nums2[i]);
                }   
                else {
                    if((nums2[i] - nums1[i]) % k) return -1;
                    else inc += (nums2[i] - nums1[i]);
                }
            }
        }
        return inc != dec ? -1 : inc / k;
    }
};