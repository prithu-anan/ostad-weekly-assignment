/*
	Time Complexity: O(n)
 	Space Complexity: O(n)
*/

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTHelper(Node* node, long long minVal, long long maxVal) {
    if (!node) return true;

    if (node->val <= minVal || node->val >= maxVal) return false;

    return isValidBSTHelper(node->left, minVal, node->val) && 
           isValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}
