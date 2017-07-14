#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int a = 13579, b = 2468, temp;;

    SingleLinkedList l1, l2;
    ListNode *pHead1 = NULL, *pHead2 = NULL, *pNode = NULL;

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

    ListNode *pHead = mergeTwoLists(pHead1, pHead2);

    // Display the merged result 
    pNode = pHead;
    cout << "Merge l1 and l2:";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}