typedef struct _TreeNode
{
	int val;
	int cnt;
	_TreeNode *left;
	_TreeNode *right;
	_TreeNode(int val)
	{
		this->val = val;
		this->cnt = 1;
		this->left = NULL;
		this->right = NULL;
	}
}TreeNode;

void test_tree_basic();