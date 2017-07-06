#include "ListFunc.h"

// Remove the next node after copying its data into the node that we were asked to delete.
void deleteNode_Normal(ListNode* pNode)
{
    ListNode *pTemp = pNode->pNext;
    pNode->val   = pTemp->val;
    pNode->pNext = pTemp->pNext;
    delete pTemp;
}

void deleteNode_Special(ListNode* pNode)
{
    ListNode *pTemp = pNode->pNext;
    *pNode = *pTemp; // Copy data and pointer
    delete pTemp;
}
