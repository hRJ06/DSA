class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        Map<Integer, ArrayList<Integer>> groupToList = new HashMap<>();
        Map<Integer, Integer> numGroup = new HashMap<>();
        int groupNo = 0, n = nums.length;
        int[] store = nums.clone();
        Arrays.sort(store);
        numGroup.put(store[0], groupNo);
        groupToList.computeIfAbsent(groupNo, k -> new ArrayList<>()).add(store[0]);
        for(int i = 1; i<n; i++) {
            if((store[i] - store[i - 1]) > limit) groupNo++;
            numGroup.put(store[i], groupNo);
            groupToList.computeIfAbsent(groupNo, k -> new ArrayList<>()).add(store[i]);
        }
        for(int i = 0; i<n; i++) {
            int group = numGroup.get(nums[i]);
            nums[i] = groupToList.get(group).get(0);
            groupToList.get(group).remove(0);
        }
        return nums;
    }
}