class Solution {
private:
    std::vector<int> perfectSubtreeSizes;

    // Function to calculate the depth of the tree and identify perfect subtrees
    std::pair<int, bool> dfs(TreeNode* node) {
        if (!node) return {0, true};  // Null node is a perfect subtree of depth 0
        
        auto [leftDepth, isLeftPerfect] = dfs(node->left);   // Recursively get left subtree depth and if it's perfect
        auto [rightDepth, isRightPerfect] = dfs(node->right); // Recursively get right subtree depth and if it's perfect
        
        if (leftDepth == rightDepth && isLeftPerfect && isRightPerfect) {
            // The subtree rooted at this node is perfect
            int size = (1 << (leftDepth + 1)) - 1;  // Size of a perfect binary tree
            perfectSubtreeSizes.push_back(size);
            return {leftDepth + 1, true};  // Return updated depth and that it's perfect
        }

        return {std::max(leftDepth, rightDepth) + 1, false};  // Not a perfect subtree
    }

public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        perfectSubtreeSizes.clear();  // Clear previous results
        dfs(root);  // Run DFS to find perfect subtrees
        
        if (perfectSubtreeSizes.empty()) return -1;  // No perfect subtrees
        
        // Sort perfect subtree sizes in descending order
        std::sort(perfectSubtreeSizes.begin(), perfectSubtreeSizes.end(), std::greater<int>());
        
        // Check if k is within bounds
        if (k > perfectSubtreeSizes.size()) return -1;
        
        return perfectSubtreeSizes[k - 1];  // Return the k-th largest perfect subtree size
    }
};
