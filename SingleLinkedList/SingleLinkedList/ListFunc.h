#include "SingleLinkedList.h"
/*237. Delete Node in a Linked List
* ！！ Description:Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
* ！！ Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,the linked list should become
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