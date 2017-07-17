#include "SingleLinkedList.h"
#include "ListFunc.h"
#include "ArrayFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int a = 73521, temp;

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

    //pHead1 = insertionSortList(pHead1);
    pHead1 = insertionSortList_Vector(pHead1);

    // Display the merged result 
    pNode = pHead1;
    cout << "Insertion sort of l1:";
    while (pNode)
    {
        cout << pNode->val << " ";
        pNode = pNode->pNext;
    }
    cout << endl;
}