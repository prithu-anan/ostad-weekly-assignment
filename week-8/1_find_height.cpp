struct Node {
	int val;
	Node* left;
	Node* right;
	
	Node(int v = 0, Node* l = nullptr, Node* r = nullptr) {
		val = v;
		left = l;
		right = r;
	}
};

int findHeight(Node* root) {
	if(root == nullptr)
		return 0;

	int leftHeight = 1 + findHeight(root->left);
	int rightHeight = 1 + findHeight(root->right);

	return max(leftHeight, rightHeight);
}
