#include<vector>
using namespace std;

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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<TreeNode*> temp;
		vector<int> result;
		if (root == NULL)
			return result;
		temp.push_back(root);
		TreeNode* p;
		while (!temp.empty())
		{
			p = temp[0];
			temp.erase(temp.begin());
			if (p->left)
				temp.push_back(p->left);
			if (p->right)
				temp.push_back(p->right);
			result.push_back(p->val);
		}
		return result;
	}
};