#include <cstdio>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): left(NULL), right(NULL), val(0) {}
	TreeNode(int v): left(NULL), right(NULL), val(v) {}
};

// 先序：首先访问左子；再访问右子
// 访问栈顶节点后
// 弹栈
// 先让右子入栈
// 再让左子入栈
void preOrder(TreeNode* itr) {
	stack<TreeNode*> stack;

	if (itr != NULL) {
		stack.push(itr);
	}

	while (!stack.empth()) {
		TreeNode* cur = stack.top();

		// do something

		stack.pop();

		if (cur->right != NULL) {
			stack.push(cur->right);
		}
		if (cur->left != NULL) {
			stack.push(cur->left);
		}
	}
}

// 中序：无左子节点后访问节点
// 持续将左子节点压栈
// 无左子节点后
// 访问节点
// 将右子节点压栈
void inOrder(TreeNode* itr) {
	stack<TreeNode*> stack;

	if (itr != NULL) {
		stack.push(itr);
	}

	while (!stack.empty()) {
		if (itr != NULL) {
			stack.push(itr);
			itr = itr->left;
		} else {
			itr = stack.top();

			// do something

			stack.pop();

			itr = itr->right;
		}
	}
}

// 后序
// 网上看的比较神奇
// 使用两个栈实现
// 节点先进入s1栈
// s1弹栈，并将s1压入s2
// 之后将s1的左右节点压入s1中
// 最后s2中的元素访问顺序即是访问顺序
void postOrder(TreeNode* itr) {
	stack<TreeNode*> s1, s2;

	if (itr != NULL) {
		s1.push_back(itr);
	}

	while (!s1.empty()) {
		TreeNode* cur = s1.top();
		s1.pop();

		s2.push(cur);

		if (cur->left != NULL)
			s1.push(cur->left);
		
		if (cur->right != NULL)
			s1.push(cur->right);
	}

	while (!s2.empty()) {
		TreeNode* cur = s2.top();

		// dosomething

		s2.pop();
	}
}

int main(int argc, char const *argv[]) {
	return 0;
}