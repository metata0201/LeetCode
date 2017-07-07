#include "SingleLinkedList.h"
#include "ListFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int a = 12, temp;
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

    //pNode = reverse_Iterative(pHead);
    pNode = reverse_Recursive(pHead);

    // Display linked list l1
    cout << "Reversed list l: ";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}