class Solution {
    public String clearDigits(String s) {
        Stack<Character> stack = new Stack<>();
        int n = s.length();
        for(int i = 0; i<n; i++) {
            char ch = s.charAt(i);
            if(Character.isDigit(ch)) {
                if(stack.size() > 0) {
                    stack.pop();
                }
            }
            else stack.push(ch);
        }   
        StringBuilder ans = new StringBuilder();
        while(!stack.empty()) {
            ans.append(stack.pop());
        }
        return ans.reverse().toString();
    }
}