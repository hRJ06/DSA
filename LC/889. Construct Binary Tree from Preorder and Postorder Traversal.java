/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode f(int preStart, int preEnd, int postStart, int[] preOrder, int[] postOrder) {
        if(preStart > preEnd) return null; /* Take the case when it is not a complete tree */
        TreeNode root = new TreeNode(preOrder[preStart]);
        if(preStart != preEnd) {
            int j = postStart;
            while(postOrder[j] != preOrder[preStart + 1]) j++;
            int num = j - postStart + 1;
            root.left = f(preStart + 1, preStart + num, postStart, preOrder, postOrder);
            root.right = f(preStart + num + 1, preEnd, j + 1, preOrder, postOrder);
            return root;
        }
        else 
            return root;

    }
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int n = preorder.length;
        return f(0, n - 1, 0, preorder, postorder);
    }
}