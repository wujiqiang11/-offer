
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		TreeNode* p = pRoot1;
		if (p->val - pRoot2->val > -0.0000001 && p->val - pRoot2->val < 0.0000001)
		{
			if (IsSubtree(p->left, pRoot2->left) && IsSubtree(p->right, pRoot2->right))
				return true;
		}
		return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
	bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL)
			return true;
		else if(pRoot1&&pRoot2)
		{
			if (pRoot1->val - pRoot2->val > -0.0000001 && pRoot1->val - pRoot2->val < 0.0000001)
				return (IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right));
			else
				return false;
		}
		else
		{
			return false
		}
	}
};