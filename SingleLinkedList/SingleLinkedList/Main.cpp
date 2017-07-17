#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int a = 123456, temp;

    SingleLinkedList l1;
    ListNode *pHead1 = NULL, *pNode = NULL;

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

    reorderList(pHead1);

    // Display the reorder result 
    pNode = pHead1;
    cout << "Reorder result:";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}