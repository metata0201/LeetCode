#include "SingleLinkedList.h"
#include "ListFunc.h"
#include <iostream>

using namespace std;

void main()
{
    int a = 1233217, temp;
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

    if (isPalindrome(pHead))
    {
        cout << a << " is a palindrome." << endl;
    }
    else
    {
        cout << a << " isn't a palindrome." << endl;
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
}