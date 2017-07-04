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
    SingleLinkedList() :pHead(nullptr){};
    ~SingleLinkedList();
public:
    ListNode* insert(int val);
    ListNode* addTwoNumbers_Reverse(ListNode* l1, ListNode* l2);

private:
    ListNode *pHead;
};