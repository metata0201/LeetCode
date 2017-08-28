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

// Level order traversal
vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> ret;
    if (root == nullptr)
        return ret;

    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int num    = Q.size();          // The number of nodes on every level
        double sum = 0;
        for (int i = 0; i < num; i++)
        {
            TreeNode *pCur = Q.front();
            sum += pCur->val;
            if (pCur->left)
                Q.push(pCur->left);     // Add its left child to the queue
            if (pCur->right)
                Q.push(pCur->right);    // Add its right child to the queue
            Q.pop();
        }
        ret.push_back(sum/num);
    }

    return ret;
}

// Depth first search:inorder(LVR)
vector<double> averageOfLevels_DFS(TreeNode* root)
{
    vector<double> sum;
    vector<int> num;
    average(root, 0, sum, num);

    // Calculate the average on every level
    for (int i = 0; i < sum.size(); i++)
    {
        sum[i] = sum[i] / num[i];
    }
    return sum;
}

void average(TreeNode *pCur, int curLevel, vector<double> &sum, vector<int> &num)
{
    if (pCur == nullptr)
        return;

    if (curLevel < sum.size())
    {
        sum[curLevel] += pCur->val;
        num[curLevel] += 1;
    }
    else
    {
        sum.push_back(pCur->val);
        num.push_back(1);
    }
    average(pCur->left, curLevel + 1, sum, num);    // Left child
    average(pCur->right,curLevel + 1, sum, num);    // Right child
}