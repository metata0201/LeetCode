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

// Insert from the front-end, and set it as the head node.
ListNode* SingleLinkedList::insert(int val)
{
    ListNode* pNode = new ListNode(val);
    pNode->pNext = pHead;
    pHead = pNode;
    return pHead;
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
        pReverse1 = reverse1.insert(p1->val);
        p1 = p1->pNext;
    }

    while (p2)  // Reverse l2
    {
        pReverse2 = reverse2.insert(p2->val);
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
        insert(sum % 10);

        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    if (p1 == NULL) // l1 <= l2
    {
        while (p2)
        {
            sum = p2->val + carry;
            carry = sum / 10;
            insert(sum % 10);
            p2 = p2->pNext;
        }
    }
    if (p2 == NULL) // l1 > l2
    {
        while (p1)
        {
            sum = p1->val + carry;
            carry = sum / 10;
            insert(sum % 10);
            p1 = p1->pNext;
        }
    }
    if (carry)
    {
        insert(carry);
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
        insert(sum % 10);
    }
    if (carry)
    {
        insert(carry);
    }

    return pHead;
}