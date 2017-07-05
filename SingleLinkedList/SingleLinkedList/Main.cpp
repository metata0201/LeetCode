#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

void main()
{
    int a = 7243, b = 564, temp;
    SingleLinkedList l1, l2;
    ListNode *pHead1 = NULL, *pHead2 = NULL, *pNode = NULL;

    // Setup linked list l1:7->2->4->3
    temp = a;
    while (temp)
    {
        pHead1 = l1.addFront(temp % 10);
        temp /= 10;
    }

    // Display linked list l1
    pNode = pHead1;
    cout << "linked list l1: ";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;

    // Setup linked list l2:5->6->4
    temp = b;
    while (temp)
    {
        pHead2 = l2.addFront(temp % 10);
        temp /= 10;
    }

    // Display linked list l2
    pNode = pHead2;
    cout << "linked list l2: ";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;

    // Add two numbers
    SingleLinkedList res;
    //ListNode *pRes = res.addTwoNumbers_Reverse(pHead1, pHead2);
    //ListNode *pRes = res.addTwoNumbers_Stack(pHead1, pHead2);
    ListNode *pRes = res.addTwoNumbers_Recursive(pHead1, pHead2);

    // Display
    pNode = pRes;
    cout << "l1 + l2: ";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}