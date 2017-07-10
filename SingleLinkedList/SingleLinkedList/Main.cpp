#include "SingleLinkedList.h"
#include "ListFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int a = 73962841, temp;
    SingleLinkedList l;
    ListNode *pHead = NULL, *pNode;
    temp = a;
    while (temp)
    {
        pHead = l.addFront(temp % 10);
        temp /= 10;
    }
    // Display linked list l1
    pNode = pHead;
    cout << "linked list: ";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;

    pNode = sortList(pHead);

    // Display linked list l1
    cout << "Sort list in ascending order: ";
    if (pNode == NULL)
    {
        cout << "empty linked list.";
    }
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}