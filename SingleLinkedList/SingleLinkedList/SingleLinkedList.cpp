#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

SingleLinkedList::~SingleLinkedList()
{
    ListNode *pNode = pHead;
    while (pHead)
    {
        pNode = pHead->pNext;
        delete pHead;
        pHead = pNode;
    }
}

// Insert from the front-end, and set it as the head node.
ListNode* SingleLinkedList::insert(int val)
{
    ListNode* pNode = new ListNode(val);
    pNode->pNext = pHead;
    pHead = pNode;
    return pHead;
}