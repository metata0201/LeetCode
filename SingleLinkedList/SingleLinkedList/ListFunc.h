#include "SingleLinkedList.h"
/*237. Delete Node in a Linked List
* ¡ª¡ª Description:Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
* ¡ª¡ª Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,the linked list should become
1 -> 2 -> 4 after calling your function.
*/
void deleteNode_Normal(ListNode* pNode);
void deleteNode_Special(ListNode* pNode);

/*234. Palindrome Linked List
*Given a singly linked list, determine if it is a palindrome.
*
*Follow up :
*Could you do it in O(n) time and O(1) space ?
*/
bool isPalindrome(ListNode* pHead);
ListNode* reverse(ListNode* pHead);

/*206. Reverse Linked List
*Reverse a singly linked list.
*
*Hint:
*A linked list can be reversed either iteratively or recursively.Could you implement both ?
*/
ListNode* reverse_Iterative(ListNode* pHead);
ListNode* reverse_Recursive(ListNode* pHead);

/*203. Remove Linked List Elements
*Remove all elements from a linked list of integers that have value val.
*
*Example
*Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
*Return: 1 --> 2 --> 3 --> 4 --> 5
*/
ListNode* removeElements_Normal(ListNode* pHead, int val);
ListNode* removeElements_Special(ListNode* pHead, int val);

/*160. Intersection of Two Linked Lists
*Write a program to find the node at which the intersection of two singly linked lists begins.
*
*For example, the following two linked lists :
*A :      a1 ¡ú a2
*               ¨K
*                 c1 ¡ú c2 ¡ú c3
*               ¨J
*B : b1 ¡ú b2 ¡ú b3
*begin to intersect at node c1.

*Notes:
*   (1)If the two linked lists have no intersection at all, return null.
*   (2)The linked lists must retain their original structure after the function returns.
*   (3)You may assume there are no cycles anywhere in the entire linked structure.
*   (4)Your code should preferably run in O(n) time and use only O(1) memory.
*/
int length(ListNode *pHead);
ListNode *getIntersectionNode_Normal(ListNode *pHeadA, ListNode *pHeadB);
ListNode *getIntersectionNode_Special(ListNode *pHeadA, ListNode *pHeadB);

/*148. Sort List
*Sort a linked list in O(n*log n) time using constant space complexity.
*/
ListNode* sortList(ListNode* pHead);
ListNode* split(ListNode* pHead, int groupSize);
ListNode* merge(ListNode* pHead1, ListNode* pHead2, ListNode *pMergedTail);

/*21. Merge Two Sorted Lists
*Merge two sorted linked lists and return it as a new list.The new list should be made by
*splicing together the nodes of the first two lists.
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

/*147. Insertion Sort List
Sort a linked list using insertion sort.
*/
ListNode* insertionSortList(ListNode* head);
ListNode* insertionSortList_Vector(ListNode* head);
