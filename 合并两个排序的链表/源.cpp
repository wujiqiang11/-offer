
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		ListNode* p3;
		ListNode* p3_head;
		ListNode* temp;
		if (p1 && p2)
		{
			if (p1->val < p2->val)
			{
				temp = p1;
				p1 = p1->next;
				temp->next = NULL;
			}
			else
			{
				temp = p2;
				p2 = p2->next;
				temp->next = NULL;
			}
		}
		else if (p1)
		{
			temp = p1;
			p1 = p1->next;
			temp->next = NULL;
		}
		else if(p2)
		{
			temp = p2;
			p2 = p2->next;
			temp->next = NULL;
		}
		else
		{
			return NULL;
		}
		p3 = temp;
		p3_head = temp;
		while (p1||p2)
		{
			if (p1 && p2)
			{
				if (p1->val < p2->val)
				{
					temp = p1;
					p1 = p1->next;
					temp->next = NULL;
				}
				else
				{
					temp = p2;
					p2 = p2->next;
					temp->next = NULL;
				}
				p3->next = temp;
				p3 = p3->next;
			}
			else if(p1)
			{
				temp = p1;
				p1 = p1->next;
				temp->next = NULL;
				p3->next = temp;
				p3 = p3->next;
			}
			else
			{
				temp = p2;
				p2 = p2->next;
				temp->next = NULL;
				p3->next = temp;
				p3 = p3->next;
			}
		}
		return p3_head;
	}
};