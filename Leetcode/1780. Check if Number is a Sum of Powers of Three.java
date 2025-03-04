class Solution {
    public boolean checkPowersOfThree(int n) {
        String base3Format = Integer.toString(n, 3);
        return !base3Format.contains("2");
    }
}