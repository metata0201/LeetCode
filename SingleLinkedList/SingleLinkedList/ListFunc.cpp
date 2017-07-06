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

/* Solution 1: First half == Reversed second half ?
*
*  Phase 1 : Find the middle.
*  Phase 2 : Reverse the second half.
*  Phase 3 : Compare the first half with the reversed second half.
*  Phase 4 : Restore to the original(so as to guarantee O(1) space).
*/
bool isPalindrome(ListNode* pHead)
{
    bool bPalindrome = true;
    if (pHead == nullptr)
    {
        return false;
    }

    // Find the middle of the list through the speed of 'pFast' is twice as the speed of 'pSlow'
    ListNode *pSlow = pHead, *pFast = pHead, *pSave;
    while (pFast->pNext && pFast->pNext->pNext)
    {
        pSlow = pSlow->pNext;
        pFast = pFast->pNext->pNext;
    }
    pSave = pSlow;

    // Reverse the second half of the linked list
    pSlow->pNext = reverse(pSlow->pNext);

    // Compare the first half and the second half
    ListNode *pNode = pHead;
    pSlow = pSlow->pNext;
    while (pSlow != nullptr)
    {
        if (pNode->val != pSlow->val)
        {
            bPalindrome = false;
            break;
        }
        pNode = pNode->pNext;
        pSlow = pSlow->pNext;
    }

    // Restore to the original linked list
    pSave->pNext = reverse(pSave->pNext);

    return bPalindrome;
}

// Return the head node pointer of the reversed linked list
ListNode* reverse(ListNode* pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    ListNode *p = pHead->pNext, *q;
    pHead->pNext = nullptr;
    while (p)
    {
        q = p->pNext;
        p->pNext = pHead;
        pHead = p;
        p = q;
    }
    return pHead;
}
