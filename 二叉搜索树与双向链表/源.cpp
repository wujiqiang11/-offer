
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return pRootOfTree;
		if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
			return pRootOfTree;
		TreeNode* head;
		if (pRootOfTree->left)
		{
			TreeNode* leftHead = Convert(pRootOfTree->left);
			TreeNode* p = leftHead;
			while (p->right)
			{
				p = p->right;
			}
			p->right = pRootOfTree;
			pRootOfTree->left = p;
			head = leftHead;
		}
		else
		{
			head = pRootOfTree;
		}
		if (pRootOfTree->right)
		{
			TreeNode* rightHead = Convert(pRootOfTree->right);
			pRootOfTree->right = rightHead;
			rightHead->left = pRootOfTree;
		}
		return head;

	}
};