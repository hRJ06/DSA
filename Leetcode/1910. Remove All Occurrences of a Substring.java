class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder stack = new StringBuilder();
        int n = s.length();
        for(int i = 0; i<n; i++) {
            char ch = s.charAt(i);
            stack.append(ch);
            if(stack.length() >= part.length() && stack.substring(stack.length() - part.length()).toString().equals(part)) {
                stack.delete(stack.length() - part.length(), stack.length());
            }
        }
        return stack.toString();
    }
}