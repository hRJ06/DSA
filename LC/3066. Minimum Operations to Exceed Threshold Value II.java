class Solution {
    public int minOperations(int[] nums, int k) {
        int count = 0, n = nums.length;
        for(int i = 0; i<n; i++) {
            if(nums[i] < k) count++;
        }   
        if(count > 0) {
            int op = 0;
            PriorityQueue<Long> pq = new PriorityQueue<Long>();
            for(int i = 0; i<n; i++) {
                pq.add((long)nums[i]);
            }
            while(count > 0) {
                long first = pq.poll();
                long second = pq.poll();
                if(first < k) count--;
                if(second < k) count--;
                long result = Math.min(first, second) * 2 + Math.max(first, second);
                if(result < k) count++;
                pq.add(result);
                op++;
            }
            return op;
        }
        return 0;
    }
}