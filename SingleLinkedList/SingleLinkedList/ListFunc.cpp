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
        return true;
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

// Return the head node pointer of the reversed linked list
ListNode* reverse_Iterative(ListNode* pHead)
{
    ListNode *pPre = nullptr, *pCurr = pHead, *pTemp;
    while (pCurr)
    {
        pTemp = pCurr->pNext;
        pCurr->pNext = pPre;
        pPre = pCurr;
        pCurr = pTemp;
    }
    return pPre;
}

ListNode* reverse_Recursive(ListNode* pHead)
{
    if (pHead==nullptr || pHead->pNext==nullptr)
    {
        return pHead;
    }

    ListNode *pNode = reverse_Recursive(pHead->pNext);
    pHead->pNext->pNext = pHead;    // first <- Second
    pHead->pNext = nullptr;

    return pNode;
}

ListNode* removeElements_Normal(ListNode* pHead, int val)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    ListNode *pNewHead = pHead, *pPre = pHead, *pCurr = pHead->pNext, *pNext;
    while (pCurr)   // Check from the second node
    {
        pNext = pCurr->pNext;
        if (pCurr->val == val)
        {
            pPre->pNext = pNext;
            delete pCurr;   // Avoid memory leak
        }
        else
        {
            pPre = pCurr;
        }
        pCurr = pNext;
    }

    // Check the head node
    if (pHead->val == val)
    {
        pNewHead = pHead->pNext;
        delete pHead;
    }

    return pNewHead;
}

// Key point:pointer to pointer
// ppPreNext -- The address of previous node's 'pNext'
//*ppPreNext -- The current node's address
ListNode* removeElements_Special(ListNode* pHead, int val)
{
    ListNode **ppPreNext = &pHead;
    ListNode *pCurr = nullptr;

    while (*ppPreNext != nullptr)
    {
        pCurr = *ppPreNext;
        if (pCurr->val == val)
        {
            *ppPreNext = pCurr->pNext;
            delete pCurr;
        }
        else
        {
            ppPreNext = &(pCurr->pNext);
        }
    }
    return pHead;
}
