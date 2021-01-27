using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* p1 = pListHead;
		ListNode* p2 = pListHead;
		for (int i = 0; i < k-1; i++)
		{
			if (p2->next)
				p2 = p2->next;
			else
			{
				return NULL;
			}
		}
		while (p2->next)
		{
			p2 = p2->next;
			p1 = p1->next;
		}
		return p1;
    }
};