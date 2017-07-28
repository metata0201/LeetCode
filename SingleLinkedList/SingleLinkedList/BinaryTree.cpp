#include "BinaryTree.h"

BinaryTree::~BinaryTree()
{

}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    TreeNode *root = nullptr;
    if (t1 || t2)
    {
        root = new TreeNode(0);
        root->val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        root->left  = mergeTrees((t1 ? t1->left  : nullptr), (t2 ? t2->left  : nullptr));
        root->right = mergeTrees((t1 ? t1->right : nullptr), (t2 ? t2->right : nullptr));
    }
    return root;
}