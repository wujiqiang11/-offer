
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		else
		{
			ListNode* p1=pHead->next;
			ListNode* p2=pHead;
			ListNode* p3=pHead->next;
			p2->next = NULL;
			while (p3)
			{
				p1 = p1->next;
				p3->next = p2;
				p2 = p3;
				p3 = p1;
			}
			return p2;
		}
	}
};