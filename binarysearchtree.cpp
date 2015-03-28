#include <stack>
#include <cstdio>

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int value;
	TreeNode(int v):value(v),left(NULL),right(NULL) {}
};

class BinarySearchTree {
public:
	/* non recursion 12.1-3 */
	void inorderTraversal(TreeNode* root);
};

void BinarySearchTree::inorderTraversal(TreeNode* root) {
	std::stack<TreeNode*> stack;

	// left child en stack
	while (root != NULL) {
		stack.push(root);
		root = root->left;
	}

	//
	while (!stack.empty()) {
		TreeNode* cur = stack.top();
		stack.pop();

		printf("%d\n", cur->value);

		// right child
		TreeNode* tmp = cur->right;

		// still left child en stack
		while (tmp != NULL) {
			stack.push(tmp);
			tmp = tmp->left;
		}
	}
}

int main(int argc, char const *argv[]) {
	TreeNode root(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	
	root.left = &n2;
	n2.right = &n3;
	n3.right = &n4;

	BinarySearchTree binarySearchTree;
	binarySearchTree.inorderTraversal(&root);

	return 0;
}