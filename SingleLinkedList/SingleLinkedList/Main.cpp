#include "SingleLinkedList.h"
#include "ListFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int a = 21345, temp;
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
    cout << "linked list l: ";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;

    //pNode = removeElements_Normal(pHead, 2);
    pNode = removeElements_Special(pHead, 2);

    // Display linked list l1
    cout << "Remove 2 from list l: ";
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