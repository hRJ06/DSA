class Solution {
    public int tupleSameProduct(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;
        if(n < 4) return 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i != j) {
                    int prod = nums[i] * nums[j];
                    mp.put(prod, mp.getOrDefault(prod, 0) + 1);
                }
            }
        }
        int ans = 0;
        for(int key : mp.keySet()) {
            int val = mp.get(key);
            ans += (val) * (val - 2);
        }
        return ans;
    }
}