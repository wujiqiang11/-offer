#include<vector>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty())
            return NULL;
        else
        {
            TreeNode* p = new TreeNode(pre[0]);
            vector<int>::iterator t2=vin.begin();
            auto t1 = pre.begin();
            for (auto it = vin.begin(); it != vin.end(); it++)
            {
                if (*it == pre[0])
                {
                    t2 = it;
                    break;
                }
                t1++;
            }
            vector<int> left_pre(pre.begin() + 1, t1 + 1);
            vector<int> left_vin(vin.begin(), t2);
            vector<int> right_pre(t1 + 1, pre.end());
            vector<int> right_vin(t2 + 1, vin.end());
            p->left = reConstructBinaryTree(left_pre, left_vin);
            p->right = reConstructBinaryTree(right_pre, right_vin);
            return p;
        }

    }
};