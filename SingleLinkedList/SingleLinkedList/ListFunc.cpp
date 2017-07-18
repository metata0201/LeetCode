#include "ListFunc.h"
#include <vector>
#include <algorithm>

using namespace std;

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

// Calculate the length of the linked list
int length(ListNode *pHead)
{
    ListNode *pCurr = pHead;
    int cnt = 0;
    while (pCurr)
    {
        cnt++;
        pCurr = pCurr->pNext;
    }
    return cnt;
}

ListNode *getIntersectionNode_Normal(ListNode *pHeadA, ListNode *pHeadB)
{
    // Calcualte the length of two linked list
    int cntA = 0, cntB = 0;
    cntA = length(pHeadA);
    cntB = length(pHeadB);

    ListNode *pLongListHead = pHeadA, *pShortListHead = pHeadB;
    if (cntA < cntB)
    {
        pLongListHead  = pHeadB;
        pShortListHead = pHeadA;
    }

    // Adjust the long list head
    int diff = (cntA >= cntB) ? (cntA - cntB) : (cntB - cntA);
    while (diff > 0)
    {
        pLongListHead = pLongListHead->pNext;
        diff--;
    }

    // Comparison
    while (pLongListHead != pShortListHead)
    {
        pLongListHead  = pLongListHead->pNext;
        pShortListHead = pShortListHead->pNext;
    }

    return pLongListHead;
}

ListNode *getIntersectionNode_Special(ListNode *pHeadA, ListNode *pHeadB)
{
    ListNode *pCurrA = pHeadA, *pCurrB = pHeadB;
    while (pCurrA != pCurrB)
    {
        pCurrA = pCurrA ? pCurrA->pNext : pHeadB;
        pCurrB = pCurrB ? pCurrB->pNext : pHeadA;
    }
    return pCurrA;
}

// Bottom-to-up and use divide-and-conquer method.
ListNode* sortList(ListNode* pHead)
{
    if (pHead==nullptr || pHead->pNext==nullptr)
    {
        return pHead;
    }

    int len = length(pHead);

    ListNode *pHead1, *pHead2, *pTail, *pCurr;
    ListNode dummyHead(0);
    dummyHead.pNext = pHead;
    for (int step = 1; step < len; step = (step << 1))
    {
        pCurr = dummyHead.pNext;
        pTail = &dummyHead;
        while (pCurr)
        {
            pHead1 = pCurr;
            pHead2 = split(pHead1, step);
            pCurr = split(pHead2, step);
            pTail = merge(pHead1, pHead2, pTail);
        }
    }

    return dummyHead.pNext;
}

// pHead     ---- Linked list head node
// groupSize ---- Divide linked list into small linked lists, whose lengths are all 'groupSize'
// Return next samll linked list head node.
ListNode* split(ListNode* pHead, int groupSize)
{
    for (int i = 1; (pHead != nullptr) && (i < groupSize); i++)
    {
        pHead = pHead->pNext;
    }

    if (pHead == nullptr) { return nullptr; }

    ListNode *pSecondHead = pHead->pNext;
    pHead->pNext = nullptr;
    return pSecondHead;
}

// Merge 'list1' and 'list2' in ascending order.
ListNode* merge(ListNode* pHead1, ListNode* pHead2, ListNode *pMergedTail)
{
    while (pHead1 && pHead2)
    {
        if (pHead1->val <= pHead2->val)
        {
            pMergedTail->pNext = pHead1;
            pMergedTail = pHead1;
            pHead1 = pHead1->pNext;
        }
        else
        {
            pMergedTail->pNext = pHead2;
            pMergedTail = pHead2;
            pHead2 = pHead2->pNext;
        }
    }

    pMergedTail->pNext = pHead1 ? pHead1 : pHead2;
    while (pMergedTail->pNext)
    {
        pMergedTail = pMergedTail->pNext;
    }

    return pMergedTail;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode dummyHead(0);
    ListNode *p = &dummyHead;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            p->pNext = l1;
            l1 = l1->pNext;
        }
        else
        {
            p->pNext = l2;
            l2 = l2->pNext;
        }
        p = p->pNext;
    }

    // Merge the rest of sorted list l1 or l2
    p->pNext = l1 ? l1 : l2;

    return dummyHead.pNext;
}

// For God's sake, don't try sorting a linked list during the interview.
ListNode* insertionSortList(ListNode* head)
{
    if (head == nullptr || head->pNext == nullptr)
    {
        return head;
    }

    ListNode dummyHead(0);
    dummyHead.pNext = head;
    ListNode *pre = &dummyHead, *cur = head;

    while (cur != nullptr)
    {
        if (cur->pNext!=nullptr && (cur->pNext)->val < cur->val)
        {
            while (pre->pNext!=nullptr && (pre->pNext)->val < (cur->pNext)->val)
            {
                pre = pre->pNext;
            }
            // Insert (cur->next) after pre
            ListNode *tmp = cur->pNext->pNext;
            cur->pNext->pNext = pre->pNext;
            pre->pNext = cur->pNext;
            cur->pNext = tmp;
            // Move pre back to dummyHead
            pre = &dummyHead;
        }
        else
        {
            cur = cur->pNext;
        }
    }

    return dummyHead.pNext;
}

ListNode* insertionSortList_Vector(ListNode* head)
{
    if (head == nullptr || head->pNext == nullptr)
    {
        return head;
    }

    ListNode *pCurr = head;
    vector<int> data;
    while (pCurr != nullptr)    // Copy the linked list val
    {
        data.push_back(pCurr->val);
        pCurr = pCurr->pNext;
    }

    // Sort the vector
    sort(data.begin(), data.end());

    // Copy the sorted vector back to the linked list.
    pCurr = head;
    for (int i = 0; i < data.size(); i++)
    {
        pCurr->val = data[i];
        pCurr = pCurr->pNext;
    }

    return head;
}

void reorderList(ListNode* head)
{
    if (head == nullptr || head->pNext == nullptr || head->pNext->pNext==nullptr)
    {
        return;
    }

    // Use speed to locate the middle of the linked list
    ListNode *pSlow = head, *pFast = head;
    while (pFast->pNext && pFast->pNext->pNext)
    {
        pSlow = pSlow->pNext;
        pFast = pFast->pNext->pNext;
    }

    // Split into two linked list, and reverse the second
    ListNode *pSecond = reverse_Iterative(pSlow->pNext);
    pSlow->pNext = nullptr;

    // Merge the two linked lists to do the reorder
    ListNode *pFirst = head, *pNext1 = nullptr, *pNext2 = nullptr;
    while (pSecond)
    {
        pNext1 = pFirst->pNext;
        pNext2 = pSecond->pNext;
        pFirst->pNext  = pSecond;
        pSecond->pNext = pNext1;
        pFirst  = pNext1;
        pSecond = pNext2;
    }
}

// Floyd's cycle detection algorithm(AKA hare-tortoise algorithm).
ListNode *detectCycle(ListNode *head)
{
    ListNode *pSlow = head, *pFast = head;
    while (pFast)
    {
        if (pFast->pNext && pFast->pNext->pNext)
        {
            pSlow = pSlow->pNext;
            pFast = pFast->pNext->pNext;
            if (pSlow == pFast)     // If there is a circle, 'pSlow' and 'pFast' should meet each other in the circle
            {
                break;
            }
        }
        else
        {
            return nullptr;         // If there is no circle
        }
    }

    // Restart 'pSlow' from the start node, both 'pSlow' and 'pFast' walk one step at a time, they will meet at entry node of the circle
    pSlow = head;
    while (pSlow != pFast)
    {
        pSlow = pSlow->pNext;
        pFast = pFast->pNext;
    }

    return pSlow;
}

// Floyd's cycle detection algorithm(AKA hare-tortoise algorithm).
bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->pNext == nullptr)
    {
        return false;
    }

    ListNode *pSlow = head, *pFast = head;
    while (pFast != nullptr)
    {
        if (pFast->pNext && pFast->pNext->pNext)
        {
            pSlow = pSlow->pNext;
            pFast = pFast->pNext->pNext;
            if (pSlow == pFast) // If there is a circle, 'pSlow' and 'pFast' should meet each other in the circle
            {
                return true;
            }
        }
        else
        {
            return false;       // If there is no circle
        }
    }
}