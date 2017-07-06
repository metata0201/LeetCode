#include "SingleLinkedList.h"
#include <iostream>
#include <stack>

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

ListNode* SingleLinkedList::head()
{
    return pHead;
}

// Get the length of the linked list
int SingleLinkedList::length()
{
    ListNode *pNode = pHead;
    int cnt = 0;
    while (pNode)
    {
        cnt++;
        pNode = pNode->pNext;
    }
    return cnt;
}

// Get the length from 'pHeadNode' of the linked list
int SingleLinkedList::length(ListNode *pHeadNode)
{
    ListNode *pNode = pHeadNode;
    int cnt = 0;
    while (pNode)
    {
        cnt++;
        pNode = pNode->pNext;
    }
    return cnt;
}

// Add node from the front, and set it as head node
ListNode* SingleLinkedList::addFront(int val)
{
    ListNode* pNode = new ListNode(val);
    if (pHead == NULL && pTail == NULL)
    {
        pHead = pNode;
        pTail = pNode;
    }
    else
    {
        pNode->pNext = pHead;
        pHead = pNode;
    }

    return pNode;
}

// Add node from the rear, and set it as tail node
ListNode* SingleLinkedList::addTail(int val)
{
    ListNode* pNode = new ListNode(val);
    if (pHead == NULL && pTail == NULL)
    {
        pHead = pNode;
        pTail = pNode;
    }
    else
    {
        pTail->pNext = pNode;
        pTail = pNode;
    }
    
    return pNode;
}

// Through reversing list l1 and l2
ListNode* SingleLinkedList::addTwoNumbers_Reverse(ListNode* l1, ListNode* l2)
{
    if ((l1 == NULL) && (l2 == NULL)){
        return NULL;
    }
    else if (l1 == NULL){
        return l2;
    }
    else if (l2 == NULL){
        return l1;
    }

    // Reverse l1 and l2
    SingleLinkedList reverse1, reverse2;
    ListNode *p1 = l1, *pReverse1 = NULL, *p2 = l2, *pReverse2 = NULL;
    while (p1)  // Reverse l1
    {
        pReverse1 = reverse1.addFront(p1->val);
        p1 = p1->pNext;
    }

    while (p2)  // Reverse l2
    {
        pReverse2 = reverse2.addFront(p2->val);
        p2 = p2->pNext;
    }

    // Add reverse1 and reverse2
    p1 = pReverse1;
    p2 = pReverse2;
    int sum = 0, carry = 0;
    while (p1 && p2)
    {
        sum = p1->val + p2->val + carry;
        carry = sum / 10;
        addFront(sum % 10);

        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    if (p1 == NULL) // l1 <= l2
    {
        while (p2)
        {
            sum = p2->val + carry;
            carry = sum / 10;
            addFront(sum % 10);
            p2 = p2->pNext;
        }
    }
    if (p2 == NULL) // l1 > l2
    {
        while (p1)
        {
            sum = p1->val + carry;
            carry = sum / 10;
            addFront(sum % 10);
            p1 = p1->pNext;
        }
    }
    if (carry)
    {
        addFront(carry);
    }

    return pHead;
}

// Through pushing linked list node into stack
ListNode* SingleLinkedList::addTwoNumbers_Stack(ListNode* l1, ListNode* l2)
{
    if ((l1 == NULL) && (l2 == NULL)){
        return NULL;
    }
    else if (l1 == NULL){
        return l2;
    }
    else if (l2 == NULL){
        return l1;
    }

    // Push linked list node into stack
    ListNode *p1 = l1, *p2 = l2;
    stack<int> stack1, stack2;
    while (p1)
    {
        stack1.push(p1->val);
        p1 = p1->pNext;
    }
    while (p2)
    {
        stack2.push(p2->val);
        p2 = p2->pNext;
    }

    // Pop stack for adding
    int sum = 0, carry = 0;
    while (!(stack1.empty() && stack2.empty()))
    {
        sum = 0;
        if (!stack1.empty())
        {
            sum += stack1.top();
            stack1.pop();
        }
        if (!stack2.empty())
        {
            sum += stack2.top();
            stack2.pop();
        }
        sum += carry;

        carry = sum / 10;
        addFront(sum % 10);
    }
    if (carry)
    {
        addFront(carry);
    }

    return pHead;
}

// Recursive to add two numbers
ListNode* SingleLinkedList::addTwoNumbers_Recursive(ListNode* l1, ListNode* l2)
{
    if ((l1 == NULL) && (l2 == NULL)){
        return NULL;
    }
    else if (l1 == NULL){
        return l2;
    }
    else if (l2 == NULL){
        return l1;
    }

    ListNode *pRes = NULL;
    int len1 = length(l1);
    int len2 = length(l2);
    if (len1 >= len2)
    {
        pRes = addTwoNumbers(l1, l2, len1 - len2);
    }
    else
    {
        pRes = addTwoNumbers(l2, l1, len2 - len1);
    }
    if (m_nCarry)
    {
        ListNode *pNode = new ListNode(m_nCarry);
        pNode->pNext = pRes;
        pRes = pNode;
    }
    pHead = pRes;

    return pRes;
}

// Recursive adding function:input l1 is longer than l2
ListNode* SingleLinkedList::addTwoNumbers(ListNode* l1, ListNode* l2, int diff)
{
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }

    ListNode *pNext = NULL;
    if (diff)
    {
        pNext = addTwoNumbers(l1->pNext, l2, diff - 1);
    }
    else
    {
        pNext = addTwoNumbers(l1->pNext, l2->pNext, 0);
    }
    int sum = l1->val + (diff ? 0 : l2->val) + m_nCarry;
    m_nCarry  = sum / 10;
    
    ListNode *pCurr = new ListNode(sum % 10);
    pCurr->pNext = pNext;

    return pCurr;
}

// Special code to add two numbers
ListNode* SingleLinkedList::addTwoNumbers_Special(ListNode* l1, ListNode* l2)
{
    if ((l1 == NULL) && (l2 == NULL)){
        return NULL;
    }
    else if (l1 == NULL){
        return l2;
    }
    else if (l2 == NULL){
        return l1;
    }

    int len1, len2, sum, carry = 0;
    len1 = length(l1);
    len2 = length(l2);

    SingleLinkedList tempList;
    ListNode *pTempHead = NULL , *p1=l1, *p2=l2;
    while (len1 > 0 && len2 > 0)
    {
        sum = 0;
        if (len1 >= len2) { sum += p1->val; p1 = p1->pNext; len1--; }
        if (len2 > len1)  { sum += p2->val; p2 = p2->pNext; len2--; }
        pTempHead = tempList.addFront(sum);
    }

    // Reverse temp linked list and process carry bit
    ListNode *pNode = pTempHead;
    while (pNode)
    {
        sum = pNode->val + carry;
        carry = sum / 10;
        addFront(sum % 10);
        pNode = pNode->pNext;
    }
    if (carry)
    {
        addFront(carry);
    }

    return pHead;
}