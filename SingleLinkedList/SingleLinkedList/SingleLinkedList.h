class ListNode
{
public:
    ListNode(int a) :val(a), pNext(nullptr){};

public:
    int val;
    ListNode *pNext;
};

class SingleLinkedList
{
public:
    SingleLinkedList() :pHead(nullptr), pTail(nullptr), m_nCarry(0){};
    ~SingleLinkedList();
public:
    ListNode* addFront(int val);
    ListNode* addTail(int val);
    ListNode* addTwoNumbers_Reverse(ListNode* l1, ListNode* l2);
    ListNode* addTwoNumbers_Stack(ListNode* l1, ListNode* l2);
    ListNode* addTwoNumbers_Recursive(ListNode* l1, ListNode* l2);

private:
    ListNode *pHead, *pTail;
    int m_nCarry;
};