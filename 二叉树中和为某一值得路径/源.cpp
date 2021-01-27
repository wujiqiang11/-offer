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
private:
	vector<vector<int>> result;
	vector<int> trace;
	int sum;
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		sum = 0;
		if (root)
		{
			dfs(root, expectNumber);
		}
		return result;
	}
	void dfs(TreeNode* node, int expectNumber)
	{
		trace.push_back(node->val);
		sum += node->val;
		if (node->left)
			dfs(node->left, expectNumber);
		if (node->right)
			dfs(node->right, expectNumber);
		if (node->left == NULL && node->right == NULL&&sum==expectNumber)
		{
			result.push_back(trace);
		}
		sum -= node->val;
		trace.erase(trace.end() - 1);
		return;
	}
};