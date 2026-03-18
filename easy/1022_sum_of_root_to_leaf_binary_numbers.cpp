/**
 * 1022. Sum of Root To Leaf Binary Numbers
 * https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers
 * 
 * You are given the root of a binary tree where each node has a value 0 or 1.
 * Each root-to-leaf path represents a binary number starting with the most significant bit.
 * 
 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
 * 
 * For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
 * 
 * The test cases are generated so that the answer fits in a 32-bits integer.
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val is 0 or 1.
 */

#include <cassert>

 /**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* node, int current) {
        if (!node) {
            return 0;
        }
        current = (current << 1) | node->val;
        if (!node->left && !node->right) {
            return current;
        }
        return dfs(node->left, current) + dfs(node->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

void Test1() {   // [1,0,1,0,1,0,1]
    TreeNode node6(1);
    TreeNode node5(0);
    TreeNode node4(1);
    TreeNode node3(0);
    TreeNode node2(1, &node5, &node6);
    TreeNode node1(0, &node3, &node4);
    TreeNode root(1, &node1, &node2);
    assert(Solution().sumRootToLeaf(&root) == 22);
}

void Test2() { // [1]
    TreeNode root(1);
    assert(Solution().sumRootToLeaf(&root) == 1);
}


void Test3() { // [0,0,1]
    TreeNode node2(1);
    TreeNode node1(0, &node2, nullptr);
    TreeNode root(0, &node1, nullptr);
    assert(Solution().sumRootToLeaf(&root) == 1);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}