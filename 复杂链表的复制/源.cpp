
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
private:
    void copy1(RandomListNode* pHead)
    {
        RandomListNode* p1;
        RandomListNode* p2;
        p1 = pHead;
        while (p1)
        {
            p2 = p1->next;
            RandomListNode* temp = new RandomListNode(p1->label);
            p1->next = temp;
            temp->next = p2;
            p1 = p2;
        }
    }
    void copy2(RandomListNode* pHead)
    {
        RandomListNode* p1 = pHead;
        RandomListNode* p2;
        while (p1)
        {
            p2 = p1->next;
            if (p1->random)
            {
                p2->random = p1->random->next;
            }
            p1 = p2->next;
        }
    }
    RandomListNode* div(RandomListNode* pHead)
    {
        RandomListNode* p1 = pHead;
        RandomListNode* p2 = p1->next;
        RandomListNode* p3 = p2->next;
        RandomListNode* p2_Head = p2;

        p1->next = NULL;
        p2->next = NULL;
        while (p3)
        {
            p1->next = p3;
            p2->next = p3->next;
            p3 = p3->next->next;
            p1 = p1->next;
            p2 = p2->next;
            p1->next = NULL;
            p2->next = NULL;
        }
        return p2_Head;
    }


public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return NULL;
        copy1(pHead);
        copy2(pHead);
        return div(pHead);
    }
};