#pragma once
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
class TreeNode
{
public:
    TreeNode(int x) :val(x), left(nullptr), right(nullptr){}

public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Definition for a binary tree.
class BinaryTree
{
public:
    BinaryTree() :root(nullptr){}
    ~BinaryTree();
public:

private:
    TreeNode *root;
};

/*617. Merge Two Binary Trees
*Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped
*while the others are not.
*
*You need to merge them into a new binary tree.The merge rule is that if two nodes overlap, then sum node values up as the new
*value of the merged node.Otherwise, the NOT null node will be used as the node of new tree.
*Example 1:
*Input :
*    Tree 1                     Tree 2
*        1                         2
*       / \                       / \
*      3   2                     1   3
*     /                           \   \
*    5                             4   7
*Output:Merged tree :
*                    3
*                   / \
*                  4   5
*                 / \   \
*                5   4   7
*Note: The merging process must start from the root nodes of both trees.
*/
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);

/*637. Average of Levels in Binary Tree
Given a non - empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input :
        3
       / \
      9  20
         / \
        15  7
Output:[3, 14.5, 11]
Explanation :
    The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11. Hence return[3, 14.5, 11].
Note :
    The range of node's value is in the range of 32-bit signed integer.
*/
vector<double> averageOfLevels_BFS(TreeNode* root); // Breadth first search
vector<double> averageOfLevels_DFS(TreeNode* root); // Depth first search
void average(TreeNode *pCur, int curLevel, vector<double> &sum, vector<int> &num);