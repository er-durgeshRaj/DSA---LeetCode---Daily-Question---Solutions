// QUESTION
// Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

// Example 1:


// Input: root = [2,1,3]
// Output: 1
// Example 2:


// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    int maxDepth;
    int bottomLeft;
    
    void solve(TreeNode* root, int currDepth) {
        if(!root) {
            return;
        }
        
        if(currDepth > maxDepth) {
            maxDepth   = currDepth;
            bottomLeft = root->val;
        }
        
        solve(root->left, currDepth+1);
        solve(root->right, currDepth+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        
        solve(root, 0);
        return bottomLeft;
        
    }
};
