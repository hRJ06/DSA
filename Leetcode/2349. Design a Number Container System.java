class NumberContainers {
    private HashMap<Integer, Integer> indexMap;
    private HashMap<Integer, TreeSet<Integer>> noIndex;
    public NumberContainers() {
        indexMap = new HashMap<>();
        noIndex = new HashMap<>();
    }
    
    public void change(int index, int number) {
        if(indexMap.containsKey(index)) {
            int _number = indexMap.get(index);
            noIndex.get(_number).remove(index);
            if(noIndex.get(_number).size() <= 0) noIndex.remove(_number);
        }
        indexMap.put(index, number);
        noIndex.computeIfAbsent(number, k -> new TreeSet<>()).add(index);
    }
    
    public int find(int number) {
        if(noIndex.containsKey(number)) return noIndex.get(number).first();
        return -1;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */