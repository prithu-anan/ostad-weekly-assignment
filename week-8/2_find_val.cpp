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

Node* findVal(Node* root, int val) {
	if(root == nullptr)
		return nullptr;
	if(val == root->val)
		return root;
	if(val < root->val)
		return findVal(root->left, val);
	if(val > root->val)
		return findVal(root->right, val);
}
