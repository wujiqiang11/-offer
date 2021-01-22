#include<vector>
#include<stack>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {}
};


class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		stack<ListNode*> s_temp;
		while (head)
		{
			s_temp.push(head);
			head = head->next;
		}
		while (!s_temp.empty())
		{
			result.push_back(s_temp.top()->val);
			s_temp.pop();
		}
		return result;
    }
};